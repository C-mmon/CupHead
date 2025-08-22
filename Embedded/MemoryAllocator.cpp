class Allocator {
public:
    class Block {
        public:
        int mId; // owner id, else if not allocate then -1
        Block* next;
        int blockIndex; //this actually represent a logical block
        int size;
        bool isFree;
        Block(int bIdx, int mId, int n)
            :blockIndex(bIdx), mId(mId), size(n), isFree(true), next(nullptr) {}
    };
    Block* head;
    int globalSizeTracker = 0;
    unordered_map<int, vector<Block*>> mp; 
    int totalSize;
    Allocator(int n) { head = new Block(0,-1,n); 
    totalSize=n; }

    int allocate(int size, int mID) {
        if (globalSizeTracker == totalSize) {
            return -1;
        }
        Block* temp = head;
        while (temp != NULL) {
            if (temp->isFree && temp->size >= size) {
                int allocStart = temp->blockIndex;
                temp->mId = mID;
                int currTempSize = temp->size;
                int remSize = temp->size-size; 
                temp->size = size;
                temp->isFree = false;
                
                if (currTempSize > size) {
                    Block* newBlock = new Block(allocStart+size, -1, remSize);
                    newBlock->next= temp->next;
                    temp->next= newBlock;
                }
                globalSizeTracker += size;
                mp[mID].push_back(temp);
                return allocStart;
            }
            temp = temp->next;
        }
        return -1;
    }

    int freeMemory(int mId) {
 if (mp.find(mId) == mp.end()) return 0;
 int freed = 0;
 for (Block* blk : mp[mId]) {
            blk->isFree = true;
            blk->mId = -1;
            freed += blk->size;
            globalSizeTracker -= blk->size;;
            while (blk->next && blk->next->isFree) {
                Block* tmp = blk->next;
                blk->size += tmp->size;
                blk->next = tmp->next;
                delete tmp;
            }
        }

        //we need tto erase the previous block as well
        Block* curr=head;
        while(curr && curr->next)
        {
            if(curr->isFree && curr->next->isFree)
            {
                                Block* tmp = curr->next;
                curr->size += tmp->size;
                curr->next = tmp->next;
                delete tmp;
            }
            else
            {
                 curr = curr->next;
            }
        }

        mp.erase(mId);
        return freed;

    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
