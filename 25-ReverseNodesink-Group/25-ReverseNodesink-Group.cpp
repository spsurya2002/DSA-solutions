                t=newNode;
                temp=temp->next;
            }
           pair<ListNode*, ListNode*>p= deleteLastNode(t);
            vl.push_back({p.first,p.second});
            g++;
            if(g==totalGroup)break;
            
[1,2,3,4,5]
2
[1,2,3,4,5]
3
[2,1,4,3,5]
[3,2,1,4,5]
[2,1,4,3,5]
[3,2,1,4,5]
[
