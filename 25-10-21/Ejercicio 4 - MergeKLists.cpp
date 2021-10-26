// Ejercicio 4: Dado una arreglo de k listas de listas vinculadas, cada lista vinculada se ordena en orden ascendente. Combine todas las listas vinculadas en una lista vinculada ordenada y devuélvala. (https://leetcode.com/problems/merge-k-sorted-lists/)
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        for(ListNode* node : lists){
            if(node != nullptr) pq.push(node);
        }

        ListNode* head = new ListNode(-1);
        ListNode* cur = head;

        while(!pq.empty()){
            ListNode* node = pq.top(); pq.pop();
            cur->next = node;
            node = node->next;
            cur = cur->next;
            cur->next = nullptr;
            if(node != nullptr){
                pq.push(node);
            }
        }

        return head->next;
    }
};
