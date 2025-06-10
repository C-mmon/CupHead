class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        string firstFolder = folder[0];
        vector <string> res;
        res.push_back(firstFolder);
        for(int i=1; i< folder.size(); i++)
        {
            string currFolder=folder[i];
            if(!currFolder.starts_with(firstFolder+'/'))
            {
                firstFolder= currFolder;
                res.push_back(currFolder);
            }
        }
        return res;
    }
};
