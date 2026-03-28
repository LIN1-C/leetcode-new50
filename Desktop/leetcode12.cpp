class Solution {
public:
    // 参数 S：当前玩家下过的所有位置（用数字 0~8 表示）
    // 参数 wins：所有能赢的连线组合（8种）
    bool checkwin(unordered_set<int>& S, vector<vector<int>>& wins) {
        // 遍历每一种获胜组合
        for (auto win : wins) {
            bool flag = true; // 先假设当前组合能赢
            // 检查这个获胜组合里的每一个位置
            for (auto pos : win) {
                // 如果玩家没下过这个位置，说明这条线不满足
                if (!S.count(pos)) {
                    flag = false;
                    break; // 不用再检查这条线了
                }
            }
            // 如果这条获胜组合的所有位置都被玩家占了 → 获胜
            if (flag) {
                return true;
            }
        }
        // 所有连线都不满足 → 没赢
        return false;
    }

    // 主函数：判断井字棋游戏结果
    string tictactoe(vector<vector<int>>& moves) {
        // 井字棋所有 8 种获胜组合（把 3x3 棋盘拍成一行 0~8）
        vector<vector<int>> wins = {
            {0,1,2}, {3,4,5}, {6,7,8},  // 横向三行
            {0,3,6}, {1,4,7}, {2,5,8},  // 纵向三列
            {0,4,8}, {2,4,6}             // 两条对角线
        };

        unordered_set<int> A, B; // A：先手玩家的位置；B：后手玩家的位置

        // 遍历每一步落子
        for (int i = 0; i < moves.size(); ++i) {
            // 把二维坐标 (x,y) 转换成一维数字 0~8
            int pos = moves[i][0] * 3 + moves[i][1];

            // 偶数步：玩家A落子（0,2,4...）
            if (i % 2 == 0) {
                A.insert(pos);       // 把位置加入A的集合
                if (checkwin(A, wins)) { // 检查A是否赢了
                    return "A";
                }
            }
            // 奇数步：玩家B落子（1,3,5...）
            else {
                B.insert(pos);       // 把位置加入B的集合
                if (checkwin(B, wins)) { // 检查B是否赢了
                    return "B";
                }
            }
        }

        // 所有步走完没人赢
        // 走满9步 → 平局Draw；没走满 → 还没结束Pending
        return (moves.size() == 9 ? "Draw" : "Pending");
    }
};
