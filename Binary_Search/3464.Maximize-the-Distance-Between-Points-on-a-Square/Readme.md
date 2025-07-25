### 3464.Maximize-the-Distance-Between-Points-on-a-Square

我们沿着原点顺时针将所有的点放入一个数组，数组元素是每个点与原点的距离（沿着边行走）。注意题目中k大于等于4，说明点和点之间的最小曼哈顿距离不可能大于side。否则四个点绕一圈，总距离就大于四倍边长了。

我们可以尝试二分搜索答案。假设猜测最小间隔距离是d，那么我们可以将任意一点作为起点，以d为极限间隔找到下一个点，以此类推找到k个点。如果第k个点没有“套圈”起点，并且离起点的距离依然大于d，那么就是一个符合条件的方案。因为k很小，我们遍历所有点作为起点都尝试一遍，时间复杂度为o(nk)，加上二分搜索的框架，总的时间复杂度是可以接受。

更具体的做法是，我们先用双指针，求得每个点i右边距离恰好不超过d的点next[i]。注意i的编号范围是0到n-1，如果i是接近套圈靠近原点的位置，next[i]的位置也可能会越过原点。故我们定义next[i]的范围是0到2n-1。

假设我们从p开始，做k次跨度为d跳转时，应该写成这样：
```cpp
for (int t=0; t<k-1; t++) {
    if (p<n)
        p = next[p];
    else
        p = next[p%n] + n;
}
```
即如果p已经越过原点了（即p>=n），那么它的下一个超出了next的定义域，故我们需要用`next[p%n]`。同时因为p的下一个必然也是越过原点的，故我们需要再加n。

在任何时刻，如果p点套圈了当初的起点（即p>=start+n），这说明无法实现在四周分布k个点的要求（因为第k个位置与第一个位置重合）。此外，即使p没有套圈起点，但是距离与起点少于d，也是说明无法实现要求。其余的情况，都说明有解。

注意，本题是一定有解的，故二分搜索的收敛解就是最优解。
