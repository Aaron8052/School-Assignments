#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include <memory>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

template <class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
	private:
		std::shared_ptr<BinaryNode<ItemType>> rootPtr;

	protected:
		int getHeightHelper(
			std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
		int getNumberOfNodesHelper(
			std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
		auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
						std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
		std::shared_ptr<BinaryNode<ItemType>> moveValuesUpTree(
			std::shared_ptr
			<BinaryNode<ItemType>>
			subTreePtr);

		virtual std::shared_ptr<BinaryNode<ItemType>>
		removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
					const ItemType target, bool &success);

		auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
					const ItemType &target,
					bool &success) const;

		std::shared_ptr<BinaryNode<ItemType>> copyTree(
			const std::shared_ptr
			<BinaryNode<ItemType>>
			oldTreeRootPtr) const;

		void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
		void preorder(void visit(ItemType &),
					std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
		void inorder(void visit(ItemType &),
					std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
		void postorder(void visit(ItemType &),
						std::shared_ptr<BinaryNode<ItemType>> treePtr) const;

	public:
		BinaryNodeTree();
		BinaryNodeTree(const ItemType &rootItem);
		BinaryNodeTree(const ItemType &rootItem,
						const std::shared_ptr<BinaryNodeTree<ItemType>>
						leftTreePtr,
						const std::shared_ptr<BinaryNodeTree<ItemType>>
						rightTreePtr);
		BinaryNodeTree(const BinaryNodeTree<ItemType> &tree);
		virtual ~BinaryNodeTree();
		bool isEmpty() const override;
		int getHeight() const override;
		int getNumberOfNodes() const override;
		ItemType getRootData() const override;
		void setRootData(const ItemType &newData) override;
		bool add(const ItemType &newData) override;
		bool remove(const ItemType &data) override;
		void clear() override;
		ItemType getEntry(const ItemType &anEntry) const override;
		bool contains(const ItemType &anEntry) const override;

		void preorderTraverse(void visit(ItemType &)) const override;
		void inorderTraverse(void visit(ItemType &)) const override;
		void postorderTraverse(void visit(ItemType &)) const override;

		BinaryNodeTree& operator=(const BinaryNodeTree &rightHandSide);
};

#include "BinaryNodeTree.hpp"
#endif
