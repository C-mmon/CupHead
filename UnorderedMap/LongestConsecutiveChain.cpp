        unordered_set<int> s(nums.begin(),nums.end());// sare numbers daal idher he
        int longest=0;

        for(int num:s){
            //check num se phele koi number nhai hai ya nhi
            if(s.find(num-1)==s.end()){
                int currentnum=num;
                int streak=1;

                //check karo consecutive number exist krte hain ya nhi
                while(s.find(currentnum+1)!=s.end()){
                    currentnum++;
                    streak++;
                }
                //longest update kardo
                longest=max(longest,streak);
            }
        }
        return longest
