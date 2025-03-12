/*
	Name: StyleScanner
	Copyright: 2021-2024
	Author: Daniel R. Collins
	Date: 04/08/21 00:05
	Description: 
		Scans approved style for student C++ assignment submissions.
		Broadly aligned with Gaddis C++ textbook styling.
		Also expect Dev-C++ style comment header.
*/
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;

// StyleScanner class
class StyleScanner {
	public:
		void printBanner();
		void printUsage();
		void parseArgs(int argc, char** argv);
		void parseFunctionArg(char* arg);
		bool getExitAfterArgs();
		bool readFile();
		void writeFile();
		void checkErrors();
		void showTokens();

	private:

		// Initial file scanning
		void scanCommentLines();
		void scanNewTypeDefs();
		void scanScopeLevels();
		void scanScopeLabels();

		// Utility functions
		int getLength(const string &line);
		int getSize(const vector<string> &vec);
		int getSize(const vector<int> &vec);

		// Helper functions
		void printError(const string &error);
		void printErrors(const string &error, const vector<int> &lines);
		int getFirstCommentLine();
		int getFirstNonspacePos(const string &line);
		int getLastNonspacePos(const string &line);
		int getStartTabCount(const string &line);
		int countFunctionLength(int startLine);
		
		// Boolean helper functions
		bool isIndentTabs(int line);
		bool isBlank(int line);
		bool isBlank(const string &line);
		bool isLeftBrace(int line);
		bool isBlankOrBrace(int line);
		bool isCommentLine(int line);
		bool isCommentBeforeCase(int line);
		bool isPunctuation(char c);
		bool isPunctuationChaser(char c);
		bool isContinuedBlockComment(int line);
		bool isLineLabel(const string &line);
		bool isLineStartOpenBrace(const string &line);
		bool isLineStartCloseBrace(const string &line);
		bool isLineEndingSemicolon(const string &line);
		bool isFunctionSymbol(const string &symbol);
		bool isOkayIndentLevel(int line);
		bool isSameScope(int startLine, int numLines);
		bool isLeadInCommentHere(int line);
		bool mayBeRunOnLine(int line);

		// Token-based helper functions
		string getNextToken(const string &s, int &pos);
		string getFirstToken(const string &s);
		string getLastToken(const string &s);
		int findTokenEnd(const string &s, int pos);
		bool isBasicType(const string &s);
		bool isNewType(const string &s);
		bool isAnyType(const string &s);
		bool isOkConstant(const string &s);
		bool isOkVariable(const string &s);
		bool isOkFunction(const string &s);
		bool isOkTypeName(const string &s);
		bool isSpacedOperator(const string &s);
		bool isStartParen(const string &s);
		bool isFunctionHeader(const string &s);
		bool isFunctionHeader(const string &s, string &name);
		bool isClassHeader(const string &s);
		bool isClassKeyword(const string &s);
		bool isNextVariableNameOk(const string& s, int pos);
		bool isPreprocessorDirective(const string &s);
		bool stringStartsWith(const string &s, const string &t);
		bool stringEndsWith(const string &s, const string &t);

		// Critical items
		void checkCriticalErrors();
		void checkAnyComments();
		void checkHeaderStart();
		void checkHeaderFormat();
		void checkFunctionLength();
		void checkInlineLength();

		// Readability items
		void checkReadabilityErrors();
		void checkLineLength();
		void checkTabUsage();
		void checkIndentLevels();
		void checkExtraneousBlanks();
		void checkVariableNames();
		void checkConstantNames();
		void checkFunctionNames();
		void checkClassNames();
		void checkPunctuationSpacing();
		void checkSpacedOperators();

		// Documentation items
		void checkDocumentationErrors();
		void checkEndlineComments();
		void checkBlanksBeforeComments();
		void checkTooFewComments();
		void checkTooManyComments();
		void checkEndlineRunonComments();
		void checkStartSpaceComments();
		void checkFunctionLeadComments();
		void checkNoErrors();

		// Member data
		string fileName;
		bool anyErrors = false;
		bool exitAfterArgs = false;
		bool doHeaderFormatCheck = true;
		bool doFunctionCommentCheck = true;
		bool doFunctionLengthCheck = true;
		bool useCarranoStyle = false;
		vector<string> fileLines;
		vector<string> newTypes;
		vector<int> commentLines;
		vector<int> scopeLevels;
};

// Enumeration for comment types
enum CommentTypes {NO_COMMENT = 0, C_COMMENT, CPP_COMMENT};

// Character codes to avoid confusing checker on this file
const char COMMA = 44;
const char SEMICOLON = 59;
const char QUESTION_MARK = 63;
const char LEFT_BRACE = 123;
const char RIGHT_BRACE = 125;

// String codes to avoid confusing checker on this file
const char C_COMMENT_START[] = {'/', '*', '\0'};
const char C_COMMENT_END[] = {'*', '/', '\0'};
const char DOUBLE_SLASH[] = {'/', '/', '\0'};
const char START_BLOCK[] = {LEFT_BRACE};

// Print program banner
void StyleScanner::printBanner() {
	cout << "\n";
	cout << "StyleScanner\n";
	cout << "------------\n";
}

// Print program usage
void StyleScanner::printUsage() {
	cout << "Usage: StyleScanner file [options]\n";
	cout << "  where options include:\n";
	cout << "\t-c use Carrano textbook styling\n";
	cout << "\t-h suppress header format check\n";
	cout << "\t-fc suppress function comment check\n";
	cout << "\t-fl suppress function length check\n";
	cout << endl;
}

// Parse arguments
void StyleScanner::parseArgs(int argc, char** argv) {
	for (int count = 1; count < argc; count++) {
		char *arg = argv[count];
		if (arg[0] == '-') {
			switch (arg[1]) {
				case 'c': useCarranoStyle = true; break;
				case 'h': doHeaderFormatCheck = false; break;
				case 'f': parseFunctionArg(arg); break;
				default: exitAfterArgs = true;
			}
		}
		else if (fileName == "") {
			fileName = arg;
		}
		else {
			exitAfterArgs = true;
		}
	}
	if (fileName == "") {
		exitAfterArgs = true;
	}
}

// Parse function-format arguments
void StyleScanner::parseFunctionArg(char* arg) {
	assert(strlen(arg) >= 3);
	assert(arg[0] == '-' && arg[1] == 'f');
	switch (arg[2]) {
		case 'c': doFunctionCommentCheck = false; break;
		case 'l': doFunctionLengthCheck = false; break;
		default: exitAfterArgs = true;
	}
}

// Get exit after args flag
bool StyleScanner::getExitAfterArgs() {
	return exitAfterArgs;
}

// Combined check-errors function
//   Prioritized by importance
void StyleScanner::checkErrors() {
	checkCriticalErrors();
	checkReadabilityErrors();
	checkDocumentationErrors();
	checkNoErrors();
}

// Check for critical errors
void StyleScanner::checkCriticalErrors() {
	checkAnyComments();
	checkHeaderStart();
	checkHeaderFormat();
	checkFunctionLength();
	checkInlineLength();
}

// Check for readability errors
void StyleScanner::checkReadabilityErrors() {
	checkTabUsage();
	checkIndentLevels();
	checkLineLength();
	checkVariableNames();
	checkConstantNames();
	checkFunctionNames();
	checkClassNames();
	checkExtraneousBlanks();
	checkPunctuationSpacing();
	checkSpacedOperators();
}

// Check for documentation errors
void StyleScanner::checkDocumentationErrors() {
	checkFunctionLeadComments();
	checkBlanksBeforeComments();
	checkTooFewComments();
	checkTooManyComments();
	checkStartSpaceComments();
	checkEndlineComments();
	checkEndlineRunonComments();
}

// Read a code file
bool StyleScanner::readFile() {

	// Open the file
	ifstream inFile(fileName);
	if (!inFile) {
		cerr << "Error: File not found.\n";
		return false;
	}

	// Read the file
	string nextLine;
	while (!inFile.eof()) {
		getline(inFile, nextLine);
		fileLines.push_back(nextLine);
	}
	inFile.close();

	// Post-processing
	scanCommentLines();
	scanNewTypeDefs();
	scanScopeLevels();
	scanScopeLabels();
	return true;
}

// Print the read file (for testing)
void StyleScanner::writeFile() {
	for (string line: fileLines) {
		cout << line << endl;
	}
	cout << endl;
}

// Get integer-length of a string
//   (Silences compiler warnings on conversion.)
int StyleScanner::getLength(const string &line) {
	return (int) line.length();	
}

// Get integer-size of a vector of strings
//   (Silences compiler warnings on conversion.)
int StyleScanner::getSize(const vector<string> &vec) {
	return (int) vec.size();	
}

// Get integer-size of a vector of ints
//   (Silences compiler warnings on conversion.)
int StyleScanner::getSize(const vector<int> &vec) {
	return (int) vec.size();	
}

// Get first nonspace position in a string
//   Returns -1 if none such.
int StyleScanner::getFirstNonspacePos(const string &line) {
	for (int i = 0; i < getLength(line); i++) {
		if (!isspace(line[i])) {
			return i;
		}
	}
	return -1;
}

// Get last nonspace position in a string
//   Returns -1 if none such.
int StyleScanner::getLastNonspacePos(const string &line) {
	for (int i = getLength(line) - 1; i >= 0; i--) {
		if (!isspace(line[i])) {
			return i;
		}
	}
	return -1;
}

// Is this line a blank (all whitespace)?
bool StyleScanner::isBlank(const string &line) {
	return getFirstNonspacePos(line) == -1;
}

// Is this line number a blank?
bool StyleScanner::isBlank(int line) {
	return isBlank(fileLines[line]);
}

// Is this line solely a left-brace?
bool StyleScanner::isLeftBrace(int line) {
	int startPos = getFirstNonspacePos(fileLines[line]);
	int endPos = getLastNonspacePos(fileLines[line]);
	return startPos != -1
		&& startPos == endPos
		&& fileLines[line][startPos] == LEFT_BRACE;
}

// Is this line either blank or a left-brace?
bool StyleScanner::isBlankOrBrace(int line) {
	return isBlank(line) || isLeftBrace(line);	
}

// Does string s start with string t?
bool StyleScanner::stringStartsWith(const string &s, const string &t) {
	return s.rfind(t, 0) == 0;
}

// Does string s end with string t?
bool StyleScanner::stringEndsWith(const string &s, const string &t) {
	return s.find(t, s.length() - t.length()) != string::npos;
}

// Find where the comment lines are
//    Assumes comments are full lines (no endline comments, etc.)
void StyleScanner::scanCommentLines() {
	commentLines.resize(getSize(fileLines));
	bool inCstyleComment = false;
	for (int i = 0; i < getSize(fileLines); i++) {
		string firstToken = getFirstToken(fileLines[i]);
		string lastToken = getLastToken(fileLines[i]);

		// Check C-style comment
		if (stringStartsWith(firstToken, C_COMMENT_START)) {
			inCstyleComment = true;
		}
		if (inCstyleComment) {
			commentLines[i] = C_COMMENT;
		}
		if (stringEndsWith(lastToken, C_COMMENT_END)) {
			inCstyleComment = false;
		}

		// Check C++-style comment
		if (commentLines[i] != C_COMMENT
			&& stringStartsWith(firstToken, DOUBLE_SLASH)) 
		{
			commentLines[i] = CPP_COMMENT;
		}
	}
}

// Is the line a (full-line) comment?
bool StyleScanner::isCommentLine(int line) {
	assert(0 <= line && line < getSize(fileLines));
	return (bool) commentLines[line];
}

// Is the line a comment before a case or default label?
bool StyleScanner::isCommentBeforeCase(int line) {
	assert(0 <= line && line < getSize(fileLines));
	if (isCommentLine(line)) {
		for (int cLine = line + 1; cLine < getSize(fileLines); cLine++) {
			if (isCommentLine(cLine)) continue;
			string firstToken = getFirstToken(fileLines[cLine]);
			if (firstToken == "case" || firstToken == "default")
				return true;
			else
				return false;
		}
	}
	return false;
}

// Does this line start with an opening brace?
bool StyleScanner::isLineStartOpenBrace(const string &line) {
	int firstPos = getFirstNonspacePos(line);
	return firstPos >= 0 && line[firstPos] == LEFT_BRACE;
}

// Does this line start with a closing brace?
bool StyleScanner::isLineStartCloseBrace(const string &line) {
	int firstPos = getFirstNonspacePos(line);
	return firstPos >= 0 && line[firstPos] == RIGHT_BRACE;
}

// Does this line start with a label of interest?
bool StyleScanner::isLineLabel(const string &line) {
	const string LABELS[] = {"case", "default",
		"public", "private", "protected"};
	string firstToken = getFirstToken(line);
	for (string label: LABELS) {
		if (firstToken == label) {
			return true;
		}
	}
	return false;
}

// Does this line end with a semicolon?
bool StyleScanner::isLineEndingSemicolon(const string &line) {
	int lastPos = getLastNonspacePos(line);
	return lastPos != -1 && line[lastPos] == SEMICOLON;
}

// Scan for new type names
//   Note currently just class/structs
//   (not actual "typedef" statements)
void StyleScanner::scanNewTypeDefs() {
	for (int i = 0; i < getSize(fileLines); i++) {
		if (!isCommentLine(i)) {
			int pos = 0;
			string line = fileLines[i];
			string prefix = getNextToken(line, pos);
			if (isClassKeyword(prefix)) {
				string name = getNextToken(line, pos);
				newTypes.push_back(name);
			}
		}
	}
}

// Basic scan for scope level at each line
//   Increments/decrements at each brace
void StyleScanner::scanScopeLevels() {
	scopeLevels.resize(getSize(fileLines));
	int scopeLevel = 0;
	for (int i = 0; i < getSize(fileLines); i++) {
		scopeLevels[i] = scopeLevel;
		if (!commentLines[i]) {
			string line = fileLines[i];
			for (int i = 0; i < getLength(line); i++) {
				switch (line[i]) {
					case LEFT_BRACE: scopeLevel++; break;
					case RIGHT_BRACE: scopeLevel--; break;
				}
			}
			
			// Adjust current line back for first closure
			if (isLineStartCloseBrace(line)) {
				scopeLevels[i]--;
			}
		}
	}
}

// Increment scope levels within labels
//   Assumes basic scope levels set first
//   Note labels only legitmate at scope level 1+.
void StyleScanner::scanScopeLabels() {
	int labelLevel = 0;
	for (int i = 0; i < getSize(fileLines); i++) {
		bool thisLineLabel = !commentLines[i] 
			&& isLineLabel(fileLines[i]);
		if (!labelLevel) {
			if (thisLineLabel) {
				labelLevel = scopeLevels[i];		
			}
		}
		else {
			if (scopeLevels[i] < labelLevel) {
				labelLevel = 0;
			}
			else if (!thisLineLabel) {
				scopeLevels[i]++;
			}
		}
	}
}

// Print basic error
void StyleScanner::printError(const string &error) {
	cout << error << "\n";
}

// Format an error report with line numbers
//   If lines vector is empty, then nothing is printed.
//   Line numbers are incremented for user display.
void StyleScanner::printErrors(const string &error, const vector<int> &lines) {

	// Flag any errors
	if (lines.size() > 0) {
		anyErrors = true;	
	}

	// Singular error
	if (lines.size() == 1) {
		cout << error << " (line " << lines[0] + 1 << ").\n";
	}

	// Multiple errors
	else if (lines.size() > 1) {
		const int MAX_SHOWN = 3;
		cout << error << " (lines " << lines[0] + 1;
		for (int i = 1; i < getSize(lines) && i < MAX_SHOWN; i++) {
			cout << ", " << lines[i] + 1;
		}
		if (lines.size() > MAX_SHOWN) {
			cout << ", etc";
		}
		cout << ").\n";
	}
}

// Print success message if no errors found.
void StyleScanner::checkNoErrors() {
	if (!anyErrors) {
		cout << "No errors found.\n";	
	}
}

// Get index of first comment line
//   Returns -1 if none whatsoever
int StyleScanner::getFirstCommentLine() {
	for (int i = 0; i < getSize(fileLines); i++) {
		if (commentLines[i]) {
			return i;
		}
	}
	return -1;
}

// Check if the file has any comment lines at all
void StyleScanner::checkAnyComments() {
	if (getFirstCommentLine() == -1) {
		printError("No comments found!");
	}
}

// Check header start
//   File should start with a comment
void StyleScanner::checkHeaderStart() {
	if (getFirstCommentLine() != 0) {
		printError("No comment on first line! (line 1).");
	}
}

// Check file header
void StyleScanner::checkHeaderFormat() {
	if (doHeaderFormatCheck) {
		vector<int> errorLines;
		const string HEADER[] = {C_COMMENT_START, "Name:", "Copyright:",
			"Author:", "Date:", "Description:"};
		int currLine = getFirstCommentLine();
		if (currLine >= 0) {
			for (string headPrefix: HEADER) {
				if (currLine >= getSize(fileLines)) {
					errorLines.push_back(currLine);
				}
				else {
					string thisLine = fileLines[currLine];
					unsigned int startIdx = getFirstNonspacePos(thisLine);
					if (thisLine.find(headPrefix, startIdx) != startIdx) {
						errorLines.push_back(currLine);
					}
				}
				currLine++;
			}
		}
		printErrors("Lacks Dev-C++ style comment header!", errorLines);
	}
}

// Check line lengths
void StyleScanner::checkLineLength() {
	const int MAX_LENGTH = 80;
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (fileLines[i].length() > MAX_LENGTH) {
			errorLines.push_back(i);
		}
	}
	printErrors("Line is too long", errorLines);
}

// How many tabs are at the start of this line?
int StyleScanner::getStartTabCount(const string &line) {
	int count = 0;
	while (count < getLength(line) && line[count] == '\t')
		count++;
	return count;
}

// Is the indent in this line using tabs?
bool StyleScanner::isIndentTabs(int line) {
	string lineStr = fileLines[line];	
	int checkToPos = getFirstNonspacePos(lineStr);

	// Limit check to scope level only
	//   Artistic style uses spaces for continuation lines
	//   Carrano uses space padding in some comments 	
	if (mayBeRunOnLine(line) || isContinuedBlockComment(line)) {
		checkToPos = min(checkToPos, scopeLevels[line]);
	}
	
	// Check for all-tabs here
	for (int i = 0; i < checkToPos; i++) {
		if (lineStr[i] != '\t') {
			return false;
		}
	}
	return true;
}

// Check endline comments
void StyleScanner::checkEndlineComments() {
	if (useCarranoStyle) return;
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (!commentLines[i]
			&& (fileLines[i].find(DOUBLE_SLASH) != string::npos
			|| fileLines[i].find(C_COMMENT_START) != string::npos))
		{
			errorLines.push_back(i);
		}
	}
	printErrors("Endline comments shouldn't be used", errorLines);
}

// Check tab usage for indents
void StyleScanner::checkTabUsage() {
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (!isIndentTabs(i)) {
			errorLines.push_back(i);
		}
	}
	printErrors("Tabs should be used for indents", errorLines);
}

// Is this line a continuing C-style block comment?
bool StyleScanner::isContinuedBlockComment(int line){
	return commentLines[line] == C_COMMENT
		&& (line > 0 && commentLines[line - 1] == C_COMMENT);
}

// Is this line possibly a run-on (continuation) statement?
bool StyleScanner::mayBeRunOnLine(int line) {
	if (line > 0 && scopeLevels[line] == scopeLevels[line - 1]
		&& !commentLines[line - 1] && !isBlank(line - 1))
	{
		string priorLine = fileLines[line - 1];
		int lastPriorChar = getLastNonspacePos(priorLine);
		if (priorLine[lastPriorChar] != SEMICOLON) {
			return true;
		}
	}
	return false;
}

// Is this line at an acceptable indent level?
bool StyleScanner::isOkayIndentLevel(int line) {

	// Ignore some cases
	if (isBlank(line) || !isIndentTabs(line)) {
		return true;
	}

	// Get scope & tab levels
	int scopeLevel = scopeLevels[line];
	int numStartTabs = getStartTabCount(fileLines[line]);

	// Comments before a case permit one less indent (sketchy at first)
	if (isCommentBeforeCase(line)) {
		return numStartTabs	== scopeLevel
			|| numStartTabs == scopeLevel - 1;
	}

	// Extra spaces after indent level
	//   Artistic Style uses spaces for run-on lines
	//   Carrano uses extra spaces in some comments
	if (mayBeRunOnLine(line) || isContinuedBlockComment(line)) {
		return numStartTabs >= scopeLevel;
	}
	
	// Standard indent case
	return numStartTabs == scopeLevel;
}

// Check indent levels
void StyleScanner::checkIndentLevels() {
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (!isOkayIndentLevel(i)) {
			errorLines.push_back(i);
		}
	}
	printErrors("Indent level errors", errorLines);
}

// Check blanks before comments (required)
void StyleScanner::checkBlanksBeforeComments() {
	if (useCarranoStyle) return;
	vector<int> errorLines;
	for (int i = 1; i < getSize(fileLines); i++) {
		if (commentLines[i]
			&& !commentLines[i - 1]
			&& !isBlankOrBrace(i - 1))
		{
			errorLines.push_back(i);
		}
	}
	printErrors("Missing blank line before comment", errorLines);
}

// Check for no comments in long stretch of statements
void StyleScanner::checkTooFewComments() {
	if (useCarranoStyle) return;
	const int LONG_STRETCH = 25;
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (commentLines[i]) {
			int end = i + 1;
			while (end < getSize(fileLines) && !commentLines[end++]);
			int span = end - i - 2;
			if (span > LONG_STRETCH) {
				errorLines.push_back(i + LONG_STRETCH / 2);
			}
			i = end;
		}
	}
	printErrors("Too few comments", errorLines);
}

// Check that next N lines all in same scope
bool StyleScanner::isSameScope(int startLine, int numLines) {
	if (startLine >= 0
		&& startLine + numLines < getSize(fileLines))
	{
		int startLevel = scopeLevels[startLine];
		for (int i = 1; i <= numLines; i++) {
			if (scopeLevels[startLine + i] != startLevel) {
				return false;
			}
		}
		return true;
	}
	return false;
}

// Check for commenting multiple single-line statements
void StyleScanner::checkTooManyComments() {
	if (useCarranoStyle) return;
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines) - 5; i++) {
		if (commentLines[i]
			&& !commentLines[i + 1]
			&& isBlank(i + 2)
			&& commentLines[i + 3]
			&& !commentLines[i + 4]
			&& isBlank(i + 5)
			&& isSameScope(i, 5))
		{
			errorLines.push_back(i + 3);
		}
	}
	printErrors("Too many comments", errorLines);
}

// Is this character an operator that expects spacing?
//    Note we must skip many symbols used for other purposes, e.g.:
//   "<", ">" used for brackets in #includes, templates
//   ">>" used at end of nested templates
//   "++", "--" pre/postfix to variable
//   "+" used in name of overloaded operator+
//   "-" used for unary negation (start number)
//   "*" used for pointer operator
//   "/" used in units (e.g., ft/sec)
bool StyleScanner::isSpacedOperator(const string &s) {
	const string SPACE_OPS[] = {"%", "<<", "<=", ">=",
		"==", "!=", "&&", "||", "=", "+=", "-=", "*=", "/="};
	for (string op: SPACE_OPS) {
		if (s == op) {
			return true;
		}
	}
	return false;
}

// Check spaces around operators
void StyleScanner::checkSpacedOperators() {
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (!isCommentLine(i)) {
			int pos = 0;
			string line = fileLines[i];
			string token = getNextToken(line, pos);
			while (token != "") {
				if (isSpacedOperator(token)) {

					// Check for space before & after
					int startPos = pos - token.length();
					if ((startPos > 0 && !isspace(line[startPos - 1]))
						|| (pos < getLength(line) && !isspace(line[pos])))
					{
						errorLines.push_back(i);
						break;
					}
				}
				token = getNextToken(line, pos);
			}
		}
	}
	printErrors("Operators should have surrounding spaces", errorLines);
}

// Check for endline C-style comments that continue to next line
//   Never seen this, but it would foil all our other comment logic.
void StyleScanner::checkEndlineRunonComments() {
	vector<int> errorLines;
	for (int i = 1; i < getSize(fileLines); i++) {
		if (!isCommentLine(i)
			&& fileLines[i].find(C_COMMENT_START) != string::npos
			&& fileLines[i].find(C_COMMENT_END) == string::npos)
		{
			errorLines.push_back(i);
		}
	}
	printErrors("Endline run-on C-style comments are cursed", errorLines);
}

// Is this a punctuation character?
//   Can't do colons, b/c of time, scope-resolution operator.
//   Can't do question mark, b/c conventionally has space before.
//   Commas in big numbers problematic (but retain check for now).
bool StyleScanner::isPunctuation(char c) {
	const char PUNCT[] = {COMMA, SEMICOLON};
	for (char punct: PUNCT) {
		if (c == punct) {
			return true;
		}
	}
	return false;
}

// Is this an acceptable post-punctuation character?
//   Quotes or escapes may follow in a string literal.
bool StyleScanner::isPunctuationChaser(char c) {
	const char CHASERS[] = {' ', '\n', '\t', '\"', '\\'};
	for (char chaser: CHASERS) {
		if (c == chaser) {
			return true;
		}
	}
	return false;
}

// Check for spaces after punctuation, but not before
void StyleScanner::checkPunctuationSpacing() {
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		string line = fileLines[i];
		for (int j = 0; j < getLength(line); j++) {
			if (isPunctuation(line[j])) {
				if (((j > 1 && isspace(line[j - 1]))
					|| (j < getLength(line) - 1
					&& !isPunctuationChaser(line[j + 1]))))
				{
					errorLines.push_back(i);
					break;
				}
			}
		}
	}
	printErrors("Punctuation should have space afterward", errorLines);
}

// Get next token from a line
//   Splits on spaces, identifiers, numbers, and punctuation.
//   Simplistic: Gets blocks of punctuation, glues grouping symbols, etc.
//   Starts at pos; updates pos to after found token.
string StyleScanner::getNextToken(const string &s, int &pos) {

	// Eat spaces
	while (pos < getLength(s) && isspace(s[pos])) {
		pos++;
	}

	// Get nothing
	if (pos >= getLength(s)) {
		return "";
	}

	// Find token end
	else {
		int start = pos;
		pos = findTokenEnd(s, pos);
		return s.substr(start, pos - start);
	}
}

// Find token end from legitimate start position
//   Can identify a word, number, or punctuation series
int StyleScanner::findTokenEnd(const string &s, int pos) {
	assert(pos < getLength(s));
	assert(!isspace(s[pos]));
	if (isalpha(s[pos]) || s[pos] == '_') {
		while (pos < getLength(s) && (isalnum(s[pos]) || s[pos] == '_')) {
			pos++;
		}
	}
	else if (isdigit(s[pos])) {
		while (pos < getLength(s) && (isdigit(s[pos]) || s[pos] == '.')) {
			pos++;
		}
	}
	else if (ispunct(s[pos])) {
		while (pos < getLength(s) && ispunct(s[pos])) {
			pos++;
		}
	}
	return pos;
}

// Get first token on a line
string StyleScanner::getFirstToken(const string &s) {
	int pos = 0;
	return getNextToken(s, pos);
}

// Get last token on a line
string StyleScanner::getLastToken(const string &s) {
	int pos = 0;
	string lastToken = "";
	string nextToken = getNextToken(s, pos);
	while (nextToken != "") {
		lastToken = nextToken;
		nextToken = getNextToken(s, pos);
	}
	return lastToken;
}

// Show all tokens in file (for testing)
void StyleScanner::showTokens() {
	for (string line: fileLines) {
		int pos = 0;
		string token = getNextToken(line, pos);
		while (token != "") {
			cout << token << endl;
			token = getNextToken(line, pos);
		}
		cout << endl;
	}
	cout << endl;
}

// Is this string a fundamental type?
bool StyleScanner::isBasicType(const string &s) {
	const string TYPES[] = {"int", "float", "double",
		"char", "bool", "string", "void"};
	for (string type: TYPES) {
		if (s == type) {
			return true;
		}
	}
	return false;
}

// Is this string a new defined type in this file?
bool StyleScanner::isNewType(const string &s) {
	for (string t: newTypes) {
		if (s == t)
			return true;
	}
	return false;
}

// Is this string any known type?
bool StyleScanner::isAnyType(const string &s) {
	return isBasicType(s) || isNewType(s);
}

// Is this string an acceptable constant name?
bool StyleScanner::isOkConstant(const string &s) {
	if (getLength(s) < 2) {
		return false;
	}
	for (char c: s) {
		if (!isupper(c) && c != '_') {
			return false;
		}
	}
	return true;
}

// Check constant names
void StyleScanner::checkConstantNames() {
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (!isCommentLine(i)) {
			int pos = 0;
			string line = fileLines[i];
			string prefix = getNextToken(line, pos);
			if (prefix == "const") {
				string type = getNextToken(line, pos);
				if (isAnyType(type)) {
					string name = getNextToken(line, pos);
					if (!isOkConstant(name)) {
						errorLines.push_back(i);
					}
				}
			}
		}
	}
	printErrors("Constants should be all-caps name", errorLines);
}

// Is this string an acceptable variable name?
bool StyleScanner::isOkVariable(const string &s) {
	if (getLength(s) < 2
		|| !islower(s[0]))
	{
		return false;
	}
	for (int i = 1; i < getLength(s); i++) {
		if (!isalnum(s[i])
			|| (isupper(s[i]) && isupper(s[i - 1])))
		{
			return false;
		}
	}
	return true;
}

// Does this token start with an open parenthesis?
bool StyleScanner::isStartParen(const string &s) {
	return getLength(s) > 0 && s[0] == '(';
}

// Does this symbol after an identifier indicate a function?
bool StyleScanner::isFunctionSymbol(const string& symbol) {
	return isStartParen(symbol)
		|| symbol == "<"
		|| symbol == "::"
		|| symbol == "::~";
}

// Check variable names
//   Note we check only first variable declared on a line.
void StyleScanner::checkVariableNames() {
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (!isCommentLine(i)) {
			int pos = 0;
			string line = fileLines[i];
			string type = getNextToken(line, pos);
			if (isAnyType(type)) {
				if (!isNextVariableNameOk(line, pos)) {
					errorLines.push_back(i);
				}
			}
		}
	}
	printErrors("Variables need full camelCase name", errorLines);
}

// Check the next variable name on this line
// On entry, we've discovered a type starting a line
// Returns true if okay, false if malformed variable name
bool StyleScanner::isNextVariableNameOk(const string& s, int pos) {
	string next = getNextToken(s, pos);

	// Skip de/constructors (type is name)
	if (isFunctionSymbol(next)) {
		return true;
	}

	// Get to variable name, eat pointer symbols
	while (next == "*" || next == "&") {
		next = getNextToken(s, pos);
	}

	// Check non-function names
	string afterSymbol = getNextToken(s, pos);
	return isFunctionSymbol(afterSymbol) || isOkVariable(next);
}

// Is this string an acceptable function name?
//   Currently same rule as for variable names.
bool StyleScanner::isOkFunction(const string &s) {
	return isOkVariable(s);
}

// Check function names
void StyleScanner::checkFunctionNames() {
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (!isCommentLine(i)) {
			string name;
			if (isFunctionHeader(fileLines[i], name)) {
				if (!isNewType(name) && !isOkFunction(name)) {
					errorLines.push_back(i);
				}
			}
		}
	}
	printErrors("Functions need full camelCase name", errorLines);
}

// Is there a lead-in comment to the function here?
bool StyleScanner::isLeadInCommentHere(int line) {

	// No room for comment
	if (line < 1)
		return false;
		
	// Handle template prefix
	if (getFirstToken(fileLines[line - 1]) == "template")
		return isLeadInCommentHere(line - 1);
	
	// Handle comment one line above
	if (isCommentLine(line - 1))
		return true;
		
	// Handle comment two lines above
	if (line > 1
			&& isBlank(line - 1)
			&& isCommentLine(line - 2))
		return true;
	
	// Failure
	return false;
}

// Check for lead-in comments before functions
void StyleScanner::checkFunctionLeadComments() {
	if (useCarranoStyle) return;
	if (doFunctionCommentCheck) {
		vector<int> errorLines;
		for (int i = 0; i < getSize(fileLines); i++) {
			if (!isCommentLine(i)
				&& scopeLevels[i] == 0
				&& isFunctionHeader(fileLines[i])
				&& !isLeadInCommentHere(i)) 
			{
				errorLines.push_back(i);
			}
		}
		printErrors("Functions should have a lead-in comment", errorLines);
	}
}

// Is the given line a function header?
bool StyleScanner::isFunctionHeader(const string &s) {
	string dummyName;
	return isFunctionHeader(s, dummyName);
}

// Is the given line a function header?
//   If so, return function name in parameter.
bool StyleScanner::isFunctionHeader(const string &s, string &name) {
	int pos = 0;
	string type = getNextToken(s, pos);
	if (isAnyType(type) && !isLineEndingSemicolon(s)) {
		name = getNextToken(s, pos);

		// Check for inline constructor (type is name)
		if (isStartParen(name)) {
			name = type;
			return true;			
		}

		// Handle after return value
		while (name == "*" || name == "&") {
			name = getNextToken(s, pos);
		}
		string nextSymbol = getNextToken(s, pos);
		if (nextSymbol == "::") {
			name = getNextToken(s, pos);
			nextSymbol = getNextToken(s, pos);
		}
		if (name == "operator" || isStartParen(nextSymbol)) {
			return true;
		}
	}
	return false;
}

// Is this string an acceptable new type name?
bool StyleScanner::isOkTypeName(const string &s) {
	if (getLength(s) < 2
		|| !isupper(s[0]))
	{
		return false;
	}
	for (int i = 1; i < getLength(s); i++) {
		if (!isalnum(s[i])
			|| (isupper(s[i]) && isupper(s[i - 1])))
		{
			return false;
		}
	}
	return true;
}

// Check class names
void StyleScanner::checkClassNames() {
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (!isCommentLine(i)) {
			int pos = 0;
			string line = fileLines[i];
			string prefix = getNextToken(line, pos);
			if (isClassKeyword(prefix)) {
				string name = getNextToken(line, pos);
				if (!isOkTypeName(name)) {
					errorLines.push_back(i);
				}
			}
		}
	}
	printErrors("Class/structs should start caps camel-case", errorLines);
}

// Is this a class/struct header line?
bool StyleScanner::isClassHeader(const string &s) {
	return isClassKeyword(getFirstToken(s));
}

// Is this the keyword for a class/struct?
bool StyleScanner::isClassKeyword(const string &s) {
	return s == "class" || s == "struct";
}

// Is this a preprocessor directive?
bool StyleScanner::isPreprocessorDirective(const string &s) {
	return getFirstToken(s) == "#";
}

// Check extraneous blank lines
//    Blank lines should only occur:
//    before comment, label, function, class, or preprocessor directive
void StyleScanner::checkExtraneousBlanks() {
	if (useCarranoStyle) return;
	vector<int> errorLines;
	for (int i = 0; i < (int) getSize(fileLines) - 2; i++) {
		if (isBlank(i)) {
			int next = i + 1;
			string nextLine = fileLines[next];
			if (!commentLines[next]
				&& !isLineLabel(nextLine)
				&& !isFunctionHeader(nextLine)
				&& !isClassHeader(nextLine)
				&& !isPreprocessorDirective(nextLine))
			{
				errorLines.push_back(i);
			}
		}
	}
	printErrors("Extraneous blank lines", errorLines);
}

// C++-style comments should have a space after slashes.
void StyleScanner::checkStartSpaceComments() {
	vector<int> errorLines;
	for (int i = 0; i < getSize(fileLines); i++) {
		int pos = 0;
		string line = fileLines[i];
		string token = getNextToken(line, pos);
		if (token == DOUBLE_SLASH
			&& pos < getLength(line)
			&& !isspace(line[pos]))
		{
			errorLines.push_back(i);
		}
	}
	printErrors("Comments need space after slashes", errorLines);
}

// Check for overly long functions.
void StyleScanner::checkFunctionLength() {
	if (doFunctionLengthCheck) {
		const int LONG_FUNC = 25;
		vector<int> errorLines;
		for (int i = 0; i < getSize(fileLines); i++) {
			if (!commentLines[i]) {
				if (isFunctionHeader(fileLines[i])) {
					if (countFunctionLength(i) > LONG_FUNC) {
						errorLines.push_back(i);
					}
				}
			}
		}
		printErrors("Function is too long!", errorLines);
	}
}

// Check for long inline functions.
void StyleScanner::checkInlineLength() {
	const int MAX_INLINE = 1;
	vector<int> errorLines;
	bool inClassHeader = false;
	for (int i = 0; i < getSize(fileLines); i++) {
		if (scopeLevels[i] == 0) {
			inClassHeader = false;
		}
		if (!commentLines[i]) {
			if (isClassHeader(fileLines[i])) {
				inClassHeader = true;
			}
			if (inClassHeader
				&& isFunctionHeader(fileLines[i])) 
			{
				if (countFunctionLength(i) > MAX_INLINE) {
					errorLines.push_back(i);
				}
			}
		}
	}
	printErrors("Inline functions are limited to one line", errorLines);
}

// Count function length from header line
int StyleScanner::countFunctionLength(int startLine) {
	int startScope = scopeLevels[startLine];
	int line = startLine + 1;
	while (line < getSize(fileLines) &&
		(isLineStartOpenBrace(fileLines[line])
			|| scopeLevels[line] > startScope))
	{
		line++;
	}
	return line - startLine - 1;
}

// Main test driver
int main(int argc, char** argv) {
	StyleScanner checker;
	checker.printBanner();
	checker.parseArgs(argc, argv);
	if (checker.getExitAfterArgs()) {
		checker.printUsage();
	}
	else {
		if (checker.readFile()) {
			checker.checkErrors();
		}
	}
	return 0;
}
