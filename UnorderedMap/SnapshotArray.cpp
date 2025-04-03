class SnapshotArray {
    public:
    int snapId=0;
    //most of the element remains same across the snapshot
    //with mnap the space complexity will be O(N*log(s));
    vector<map<int, int>> snapArr;
        SnapshotArray(int length) {
                    snapArr.resize(length);
            for (int i = 0; i < length; i++) {
                snapArr[i][0] = 0; // Initialize with version 0
            }
        }
        
        void set(int index, int val) {
            snapArr[index][snapId] = val;
        }
        
        int snap() {
            snapId++;
            return snapId-1;
        }
        
        int get(int index, int snap_id) {
            auto it = snapArr[index].upper_bound(snap_id);
            return prev(it)->second;
        }
    };

    //Question: https://leetcode.com/problems/snapshot-array/description/?envType=study-plan&id=level-1
    //Why are we taking map instead of vector?
    //Because the map will take O(log(s)) time to find the last version of the element in the snapshot.
    