//#include "RedBlackTree.h"
//#include <iostream>
//#include <Windows.h>
//using namespace std;
//
//enum class ConsoleColor
//{
//	BLACK = 0,
//	RED = FOREGROUND_RED,
//	GREEN = FOREGROUND_GREEN,
//	BLUE = FOREGROUND_BLUE,
//	YELLOW = RED | GREEN,
//	MAGENTA = RED | BLUE,
//	WHITE = RED | GREEN | BLUE,
//};
//
//void SetCursorPosition(int x, int y)
//{
//	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
//	::SetConsoleCursorPosition(output, pos);
//}
//
//void SetCursorColor(ConsoleColor color)
//{
//	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
//	::SetConsoleTextAttribute(output, static_cast<SHORT>(color));
//}
//
//void ShowConsoleCursor(bool flag)
//{
//	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO cursorInfo;
//	::GetConsoleCursorInfo(output, &cursorInfo);
//	cursorInfo.bVisible = flag;
//	::SetConsoleCursorInfo(output, &cursorInfo);
//}
//
//RedBlackTree::RedBlackTree()
//{
//	_nil = new Node();		// Black
//	_root = _nil;
//}
//
//RedBlackTree::~RedBlackTree()
//{
//	delete _nil;
//}
//
//void RedBlackTree::Print()
//{
//	::system("cls");
//	ShowConsoleCursor(false);
//	Print(_root, 10, 0); ;
//}
//
//void RedBlackTree::Print(Node* node, int x, int y)
//{
//	if (node == _nil)
//		return;
//
//	SetCursorPosition(x, y);
//
//
//	if (node->color == Color::Black)
//		SetCursorColor(ConsoleColor::BLUE);
//	else
//		SetCursorColor(ConsoleColor::RED);
//
//	cout << node->key;
//	Print(node->left, x - (5 / (y + 1)), y + 1);
//	Print(node->right, x + (5 / (y + 1)), y + 1);
//
//	SetCursorColor(ConsoleColor::WHITE);
//}
//
//Node* RedBlackTree::Search(Node* node, int key)
//{
//	if (node == _nil || key == node->key)
//		return node;
//
//	if (key < node->key)
//		return Search(node->left, key);
//	else
//		return Search(node->right, key);
//}
//
//Node* RedBlackTree::Min(Node* node)
//{
//	while (node->left != _nil)
//		node = node->left;
//
//	return node;
//}
//
//Node* RedBlackTree::Max(Node* node)
//{
//	while (node->right != _nil)
//		node = node->right;
//
//	return node;
//}
//
//Node* RedBlackTree::Next(Node* node)
//{
//	if (node->right != _nil)
//		return Min(node->right);
//
//	Node* parent = node->parent;
//	while (parent != _nil && node == parent->right)
//	{
//		node = parent;
//		parent = parent->parent;
//	}
//
//	return parent;
//}
//
//void RedBlackTree::Insert(int key)
//{
//	Node* newNode = new Node();
//	newNode->key = key;
//
//	Node* node = _root;
//	Node* parent = _nil;
//
//	while (node != _nil)
//	{
//		parent = node;
//		if (key < node->key)
//			node = node->left;
//		else
//			node = node->right;
//	}
//
//	newNode->parent = parent;
//
//	if (parent == _nil)
//		_root = newNode;
//	else if (key < parent->key)
//		parent->left = newNode;
//	else
//		parent->right = newNode;
//
//	// 검사
//	newNode->left = _nil;
//	newNode->right = _nil;
//	newNode->color = Color::Red;
//
//	InsertFixup(newNode);
//}
//
//void RedBlackTree::InsertFixup(Node* node)
//{
//	// 1) p = red, uncle = red
//	// -> p = black, uncle = black, pp = red로 바꿈
//	// 2) p = red, uncle = black (triangle)
//	// -> 회전을 통해 case 3으로 바꿈
//	// 3) p = red, uncle = black (list)
//	// -> 색상 변경 + 회전
//
//	//            [pp(B)]
//	//        [p(R)]     [u(?)]
//	//           [n(R)]
//	while (node->parent->color == Color::Red)
//	{
//		if (node->parent == node->parent->parent->left)
//		{
//			Node* uncle = node->parent->parent->right;
//			//            [pp(B)]			               [pp(R)]
//			//        [p(R)]     [u(R)]		           [p(B)]     [u(B)]
//			//           [n(R)]					           [n(R)]
//			if (uncle->color == Color::Red)
//			{
//				node->parent->color = Color::Black;					// p
//				uncle->color = Color::Black;							// u
//				node->parent->parent->color = Color::Red;			// pp
//				node = node->parent->parent;
//			}
//			else
//			{
//				//            [pp(B)]						     [pp(B)]		
//				//        [p(R)]     [u(B)]				    [n(R)]     [u(B)]
//				//           [n(R)]				        [p(R)]
//				// triangle
//				if (node == node->parent->right)
//				{
//					node = node->parent;
//					LeftRotate(node);
//				}
//
//				//            [pp(B)]				         [pp(R)]				         [p(B)]
//				//        [p(R)]     [u(B)]			     [p(B)]     [u(B)]			    [n(R)]     [pp(R)]
//				//     [n(R)]						   [n(R)]						   			       [u(B)]
//				// list
//				node->parent->color = Color::Black;
//				node->parent->parent->color = Color::Red;
//				RightRotate(node->parent->parent);
//			}
//		}
//		else
//		{
//			Node* uncle = node->parent->parent->left;
//			//            [pp(B)]				              [pp(R)]
//			//        [u(R)]     [p(R)]			          [u(B)]     [p(B)]
//			//                       [n(R)]			                      [n(R)]
//			if (uncle->color == Color::Red)
//			{
//				node->parent->color = Color::Black;					// p
//				uncle->color = Color::Black;							// u
//				node->parent->parent->color = Color::Red;			// pp
//				node = node->parent->parent;
//			}
//			else
//			{
//				//            [pp(B)]						     [pp(B)]		
//				//        [u(B)]     [p(R)]				    [u(B)]     [n(R)]
//				//                  [n(R)]				                   [p(R)]
//				// triangle
//				if (node == node->parent->left)
//				{
//					node = node->parent;
//					RightRotate(node);
//				}
//
//				//            [pp(B)]				            [pp(R)]				                [p(B)]		
//				//       [u(B)]     [p(R)]		          [u(B)]     [p(B)]				         [pp(R)]     [n(R)]
//				//                      [n(R)]		                      [n(R)]		      [u(B)]                
//				// list
//				node->parent->color = Color::Black;
//				node->parent->parent->color = Color::Red;
//				LeftRotate(node->parent->parent);
//			}
//		}
//	}
//
//	_root->color = Color::Black;
//}
//
//void RedBlackTree::Delete(int key)
//{
//	Node* deleteNode = Search(_root, key);
//	Delete(deleteNode);
//}
//
//// 먼저 BST 삭제 실행
////            [20]			                   [20]
////    [10(B)]      [30]			    [15(B)]     [30]
////      [15(R)]  [25] [40]		                   [25] [40]
//void RedBlackTree::Delete(Node* node)
//{
//	if (node == _nil)
//		return;
//
//	if (node->left == _nil) 
//	{
//		Color color = node->color;
//		Node* right = node->right;
//		Replace(node, node->right);
//
//		if (color == Color::Black)
//			DeleteFixup(right);
//	}
//	else if (node->right == _nil)
//	{
//		Color color = node->color;
//		Node* left = node->left;
//		Replace(node, node->left);
//
//		if (color == Color::Black)
//			DeleteFixup(left);
//	}
//	else
//	{
//		// 다음 데이터 찾기
//		Node* next = Next(node);
//		node->key = next->key;
//		Delete(next);
//	}
//
//
//}
//
//// 먼저 BST 삭제 실행...
//// - Case1) 삭제할 노드가 Red -> 그냥 삭제! 끝!
//// - Case2) root가 DB -> 그냥 추가 Black 삭제! 끝!
//// - Case3) DB의 sibling 노드가 Red
//// -- s = black, p = red (s <-> p 색상 교환)
//// -- DB 방향으로 rotate(p) 
//// -- goto other case
//// - Case4) DB의 sibling 노드가 Black && sibling의 양쪽 자식도 Black
//// -- 추가 Black을 parent에게 이전
//// --- p가 Red이면 Black 됨.
//// --- p가 Black이면 DB 됨.
//// -- s = red
//// -- p를 대상으로 알고리즘 이어서 실행 (DB가 여전히 존재하면)
//// - Case5) DB의 sibling 노드가 Black && sibling의 near child = red, far child = black
//// -- s <-> near 색상 교환
//// -- far 방향으로 rotate(s)
//// -- goto case 6
//// - Case6) DB의 sibling 노드가 Black && sibling의 far child = red
//// - p <-> s 색상 교환
//// - far = black
//// - rotate(p) (DB 방향으로)
//// - 추가 Black 제거
//void RedBlackTree::DeleteFixup(Node* node)
//{
//	Node* x = node;
//
//	// [Case1] 삭제할 노드가 Red -> 그냥 삭제! 끝!
//	// [Case2] root가 DB -> 그냥 추가 Black 삭제! 끝!
//	while (x != _root && x->color == Color::Black)
//	{
//		//		[p]
//		//	[x(B)]	[s(?)]
//		if (x == x->parent->left)
//		{
//			// [Case3] DB의 sibling 노드가 Red
//			//		[p(B)]		  		[p(R)]					[s(B)]
//			//	[x(DB)]	[s(R)]	  	[x(DB)]	[s(B)]			[p(R)]	
//			//		  [1]				  [1]		  [x(DB)]    [1]
//			Node* s = x->parent->right;
//			if (s->color == Color::Red)
//			{
//				s->color = Color::Black;
//				x->parent->color = Color::Red;
//
//				LeftRotate(x->parent);
//				s = x->parent->right;			// [1]
//			}
//			
//			// [Case4] DB의 sibling 노드가 Black && sibling의 양쪽 자식도 Black
//			if (s->left->color == Color::Black && s->right->color == Color::Black)
//			{
//				s->color = Color::Red;
//				x = x->parent;
//			}
//			else 
//			{
//				// [Case 5] DB의 sibling 노드가 Black && sibling의 near child = red, far child = black
//				//			  [p]				   				[p]					    		 [p]
//				//	[x(DB)]			[s(B)]			 [x(DB)]			[s(R)]			  [x(DB)]	[near(B)]
//				//			[near(R)]	[far(B)]   				[near(B)]	[far(B)]	 					[s(R)]
//				//																								[far(B)]
//				if (s->right->color == Color::Black)
//				{
//					s->left->color = Color::Black;
//					s->color = Color::Red;
//					RightRotate(s);
//					s = x->parent->right;
//				}
//
//				// [Case 6] DB의 sibling 노드가 Black && sibling의 far child = red
//				// 		    [p]				   		    [p(B)]				 		   [s(B)]
//				//   [x(DB)]	[s(B)]		     [x(DB)]	[s(B)]					[p(B)] 	
//				//  				[far(R)]    				[far(B)]	  [x(DB)]	 [far(B)]
//				s->color = x->parent->color;
//				x->parent->color = Color::Black;
//				s->right->color = Color::Black;
//				LeftRotate(x->parent);
//				x = _root;
//			}
//		}
//		else
//		{
//			// [Case3] DB의 sibling 노드가 Red
//			//		[p(B)]		  		[p(R)]					[s(B)]
//			//	[x(DB)]	[s(R)]	  	[x(DB)]	[s(B)]			[p(R)]	
//			//		  [1]				  [1]		  [x(DB)]    [1]
//			Node* s = x->parent->left;
//			if (s->color == Color::Red)
//			{
//				s->color = Color::Black;
//				x->parent->color = Color::Red;
//
//				RightRotate(x->parent);
//				s = x->parent->left;			// [1]
//			}
//
//			// [Case4] DB의 sibling 노드가 Black && sibling의 양쪽 자식도 Black
//			if (s->right->color == Color::Black && s->left->color == Color::Black)
//			{
//				s->color = Color::Red;
//				x = x->parent;
//			}
//			else
//			{
//				// [Case 5] DB의 sibling 노드가 Black && sibling의 near child = red, far child = black
//				//			  [p]				   				[p]					    		 [p]
//				//	[x(DB)]			[s(B)]			 [x(DB)]			[s(R)]			  [x(DB)]	[near(B)]
//				//			[near(R)]	[far(B)]   				[near(B)]	[far(B)]	 					[s(R)]
//				//																								[far(B)]
//				if (s->left->color == Color::Black)
//				{
//					s->right->color = Color::Black;
//					s->color = Color::Red;
//					LeftRotate(s);
//					s = x->parent->left;
//				}
//
//				// [Case 6] DB의 sibling 노드가 Black && sibling의 far child = red
//				// 		    [p]				   		    [p(B)]				 		   [s(B)]
//				//   [x(DB)]	[s(B)]		     [x(DB)]	[s(B)]					[p(B)] 	
//				//  				[far(R)]    				[far(B)]	  [x(DB)]	 [far(B)]
//				s->color = x->parent->color;
//				x->parent->color = Color::Black;
//				s->left->color = Color::Black;
//				RightRotate(x->parent);
//				x = _root;
//			}
//		}
//	}
//
//	x->color = Color::Black;
//}
//
//// u 서브트리를 v 서브트리로 교체
//// 그리고 delete u
//void RedBlackTree::Replace(Node* u, Node* v)
//{
//	if (u->parent == _nil)
//		_root = v;
//	else if (u == u->parent->left)
//		u->parent->left = v;
//	else
//		u->parent->right = v;
//
//	v->parent = u->parent;
//
//	delete u;
//}
//
////        [y]
////     [x]   [3]
////   [1] [2]
//
////      [x]
////   [1]   [y]
////       [2] [3]
//void RedBlackTree::LeftRotate(Node* x)
//{
//	Node* y = x->right;
//
//	x->right = y->left;		// [2]
//	if (y->left != _nil)
//		y->left->parent = x;
//
//	y->parent = x->parent;
//	if (x->parent == _nil)
//		_root = y;
//	else if (x == x->parent->left)
//		x->parent->left = y;
//	else
//		x->parent->right = y;
//
//	y->left = x;
//	x->parent = y;
//}
//
////        [y]
////     [x]   [3]
////   [1] [2]
//
////      [x]
////   [1]   [y]
////       [2] [3]
//void RedBlackTree::RightRotate(Node* y)
//{
//	Node* x = y->left;
//
//	y->left = x->right;		// [2]
//	if (y->right != _nil)
//		y->right->parent = x;
//
//	x->parent = y->parent;
//	if (y->parent == _nil)
//		_root = x;
//	else if (y == y->parent->left)
//		y->parent->left = x;
//	else
//		y->parent->right = x;
//
//	x->right = y;
//	y->parent = x;
//}
