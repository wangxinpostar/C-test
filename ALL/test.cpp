// #include<bits/stdc++.h>
// using namespace std;
// struct XY
// {
//     double x,y;
// };
// bool f[100005]={1,1};

// void E(int x)
// {
//     for(int i=2;i<=x;i++)
//     {
//         if(f[i])
//         {
//             continue;
//         }
//         for(int j=i*2;j<=x;j+=i)
//         {
//             f[j]=true;
//         }
//     }
// }

// struct T
// {
//     int a,b,n;
// }m[100];
	//存储遍历结果的数组前
	// vector<int> v;
	// //前序遍历函数
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root==nullptr) return v;
    //     v.emplace_back(root->val); //输入数组语句
    //     preorderTraversal(root->left);
    //     preorderTraversal(root->right);
    //     return v;
    // }
	//存储遍历结果的数组
	// vector<int>v;
    // //中序遍历函数
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(root==nullptr) return v;
    //     inorderTraversal(root->left);
    //     v.emplace_back(root->val);  //输入数组语句
    //     inorderTraversal(root->right);
    //     return v;
    // }
    //存储结果数组后
 	// vector<int> v;
 	// //后序遍历函数
    // vector<int> postorderTraversal(TreeNode* root) {
    //     if(root == nullptr) return v;
    //     postorderTraversal(root->left);
    //     postorderTraversal(root->right);
    //     v.emplace_back(root->val); //输入语句
    //     return v;
    // }

#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int m[N],p[N];
int main()
{
    int n,k;
    long long ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
    }
    sort(m,m+n);
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        int t=1000000;
        while(j<n)
        {
            if(!p[j]&&(m[i]+m[j])%k==0)
            {
                p[j]=1;
                t=min(t,m[j]);
            }
            j++;
        }
        cout<<t<<"\n";
        if(t!=1000000)
        {
            ans+=min(t,m[i])*min(t,m[i]);
        }
    }
    cout<<ans;
}
// int main()
// {

    // int n,m;
    // cin>>n;
    // E(100005);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>m;
    //     if(!f[m])
    //     {
    //         cout<<m<<" ";
    //     }
    // } 


    // XY m[3];
    // for(int i=0;i<3;i++)
    // {
    //     cin>>m[i].x>>m[i].y;
    // }
    // double d = sqrt (pow(m[0].x-m[1].x,2)+pow(m[0].y-m[1].y,2))+
    // sqrt (pow(m[0].x-m[2].x,2)+pow(m[0].y-m[2].y,2))+
    // sqrt (pow(m[2].x-m[1].x,2)+pow(m[2].y-m[1].y,2));
    // printf("%.2f",d);

    // int n,m,t,p;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>t;
    //     if(t==1)
    //     {
    //         continue;
    //     }
    //     p=1;
    //     for(int j=2;j*j<=t;j++)
    //     {
    //         if(t%j==0)
    //         {
    //             p=0;
    //             break;
    //         }
    //     }
    //     if(p)
    //     {
    //         cout<<t<<" ";
    //     }
    // }

//     cout<<R"(                ********
//                ************
//                ####....#.
//              #..###.....##....
//              ###.......######              ###            ###
//                 ...........               #...#          #...#
//                ##*#######                 #.#.#          #.#.#
//             ####*******######             #.#.#          #.#.#
//            ...#***.****.*###....          #...#          #...#
//            ....**********##.....           ###            ###
//            ....****    *****....
//              ####        ####
//            ######        ######
// ##############################################################
// #...#......#.##...#......#.##...#......#.##------------------#
// ###########################################------------------#
// #..#....#....##..#....#....##..#....#....#####################
// ##########################################    #----------#
// #.....#......##.....#......##.....#......#    #----------#
// ##########################################    #----------#
// #.#..#....#..##.#..#....#..##.#..#....#..#    #----------#
// ##########################################    ############)";

// }