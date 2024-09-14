class SegmentTree{
private:
    vector<int> tree, lazy;
    int size;

    void push(int segIndex, int start, int end){
        if(lazy[segIndex] != 0){
            tree[segIndex] = lazy[segIndex];
            if(start != end){
                lazy[segIndex*2 + 1] = lazy[segIndex];
                lazy[segIndex*2 + 2] = lazy[segIndex];
            }
            lazy[segIndex] = 0;
        }
    }

    int query(int segIndex, int start, int end, int left, int right){
        push(segIndex, start, end);

        if(left > end || right < start){
            return 0;
        }

        if(left <= start  && end <= right){
            return tree[segIndex];
        }

        int mid = start + (end - start)/2;

        return max(query(segIndex*2 + 1 ,start, mid, left, right), 
                    query(segIndex*2 + 2 , mid+1, end, left, right));
    }

    void update(int segIndex, int start, int end, int left, int right, int height){
        push(segIndex, start, end);

        if(left > end || right < start){
            return;
        }

        if(left <= start  && end <= right){
            tree[segIndex] = height;
            if(start != end){
                lazy[segIndex*2 + 1] = height;
                lazy[segIndex*2 + 2] = height;
            }
            return;
        }

        int mid = start + (end - start)/2;
        update(segIndex*2 + 1, start, mid, left, right, height);
        update(segIndex*2 + 2, mid+1, end, left, right, height);

        tree[segIndex] = max(tree[segIndex*2 + 1], tree[segIndex*2 + 2]);
    }

public: 
    SegmentTree(int size){
        tree.assign(4*size, 0);
        lazy.assign(4*size, 0);
        this->size = size;
    }

    int query(int left, int right){
        return query(0, 0, size - 1, left, right);
    }

    void update(int left, int right, int height){
        update(0, 0, size - 1, left, right, height);
    }

};


class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> coord;
        map<int, int> map;

        for(auto pos : positions){
            coord.push_back(pos[0]);
            coord.push_back(pos[0] + pos[1] - 1);
        }

        sort(coord.begin(), coord.end());

        coord.erase(unique(coord.begin(), coord.end()), coord.end());

        for(int i=0; i < coord.size(); i++){
            map[coord[i]] = i;
        }

        SegmentTree seg(coord.size());
        vector<int> ans;
        int maxHeight = 0;

        for(auto pos : positions){
            int left = map[pos[0]];
            int right = map[pos[0] + pos[1] - 1];

            int height = seg.query(left, right) + pos[1];
            seg.update(left, right, height);
            maxHeight = max(maxHeight, height);
            ans.push_back(maxHeight);

        }

        return ans;
    }
};
