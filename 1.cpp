#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <deque>
using namespace std;

class 23 - 2 - 1
{
private:
    /* data */
public:
    23 - 2 - 1(/* args */);
    ~23 - 2 - 1();

    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, sum = 0;
        int result = INT32_MAX;
        for (int k = 0; k < nums.size(); k++)
        {
            sum += nums[k];
            while (sum >= target)
            {
                result = result > (k - i + 1) ? (k - i + 1) : result;
                sum -= nums[i++];
            }
        }

        return result == INT32_MAX ? 0 : result;
    }

    int totalFruit(vector<int> & fruits)
    {
        int i = 0, max = 0;
        int n = fruits.size();
        unordered_map<int, int> diff;
        for (int k = 0; k < n; k++)
        {
            diff[fruits[k]]++;
            while (diff.size() > 2)
            {
                diff[fruits[i]]--;
                if (diff[fruits[i]] - 1 == 0)
                {
                    diff.erase(fruits[i]);
                }
                i++;
                if (diff.size() < 3)
                {
                    int total = 0;
                    for (auto x : diff)
                    {
                        total += x.second;
                    }
                    max = max < total ? total : max;
                }
            }
        }
        return max;
    }

    string minWindow(string s, string t)
    {
        int i = 0;
        int n = s.size();
        unordered_map<char, int> result;
        unordered_map<char, int> temp;
        string resultString(n + 1, 'a');

        if (t.size() > n)
        {
            return "";
        }
        for (int k = 0; k < n; k++)
        {

            bool b = true;
            result[s[k]]++;
            while (b && i <= k)
            {
                temp = result;
                for (auto &ch : t)
                {
                    if (!temp.count(ch) || !temp[ch])
                    {
                        b = false;
                        break;
                    }
                    temp[ch]--;
                }
                if (b)
                {
                    resultString = (resultString.size() > (k - i + 1)) ? s.substr(i, (k - i + 1)) : resultString;
                    result[s[i++]]--;
                }
            }
        }
        return resultString.size() == (n + 1) ? "" : resultString;
    }

    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        int i, k;
        int loop = n / 2;
        int mid = n / 2;
        int offset = 1;
        int count = 1;
        while (loop--)
        {
            i = startx;
            k = starty;
            for (; k < n - offset; k++)
            {
                result[i][k] = count++;
            }

            for (; i < n - offset; i++)
            {
                result[i][k] = count++;
            }

            for (; k > starty; k--)
            {
                result[i][k] = count++;
            }

            for (; i > startx; i--)
            {
                result[i][k] = count++;
            }

            startx++, starty++;
            offset++;
        }
        if (n % 2)
        {
            result[mid][mid] = count;
        }

        return result;
    }

    int search(vector<int> & nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            int num = nums[mid];
            if (num < target)
            {
                left = mid + 1;
            }
            else if (num > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    };

    int searchInsert(vector<int> & nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            int num = nums[mid];
            if (num == target)
            {
                return mid;
            }
            else if (num < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int> & nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            int num = nums[mid];
            if (num == target)
            {
                int l = mid - 1, r = mid + 1;
                while (l >= 0 && nums[l] == target)
                {
                    l--;
                }
                while (r < nums.size() && nums[r] == target)
                {
                    r++;
                }
                vector<int> res(2);
                res[0] = l + 1;
                res[1] = r - 1;
                return res;
            }
            else if (num < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return vector<int>(2, -1);
    }

    int removeElement(vector<int> & nums, int val)
    {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }

    // 链表
    ListNode *removeElements(ListNode * head, int val)
    {
        while (head && head->val == val)
        {
            head = head->next;
        }
        if (!head)
        {
            return head;
        }
        ListNode *p = head;
        while (p->next)
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }

    // 链表2
    ListNode *removeElements(ListNode * head, int val)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;
        while (current->next)
        {
            if (current->next->val == val)
            {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }

    // 设计链表
    class MyLinkedList
    {
    public:
        struct Node
        {
            int val;
            Node *next;
            Node(int val) : val(val), next(nullptr) {}
        };
        MyLinkedList()
        {
            dummy = new Node(0);
            size = 0;
        }

        int get(int index)
        {
            if (index >= size || index < 0)
            {
                return -1;
            }
            Node *current = dummy->next;
            while (index--)
            {
                current = current->next;
            }
            return current->val;
        }

        void addAtHead(int val)
        {
            Node *node = new Node(val);
            node->next = dummy->next;
            dummy->next = node;
            size++;
        }

        void addAtTail(int val)
        {
            Node *node = new Node(val);
            Node *current = dummy;

            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = node;
            size++;
        }

        void addAtIndex(int index, int val)
        {
            if (index == size)
            {
                addAtTail(val);
            }
            else if (index <= 0)
            {
                addAtHead(val);
            }
            else if (index > 0 && index < size)
            {
                Node *current = dummy;
                Node *node = new Node(val);
                while (index--)
                {
                    current = current->next;
                }
                node->next = current->next;
                current->next = node;
                size++;
            }
        }

        void deleteAtIndex(int index)
        {
            if (index >= 0 && index < size && size > 0)
            {
                Node *current = dummy;
                while (index--)
                {
                    current = current->next;
                }
                Node *temp = current->next;
                if (current->next->next)
                {
                    current->next = current->next->next;
                }
                delete temp;
                size--;
            }
        }

    private:
        Node *dummy;
        int size;
    };

    // 反转链表 双指针法
    ListNode *reverseList(ListNode * head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    // 反转链表 递归
    ListNode *recursion(ListNode * pre, ListNode * cur)
    {
        if (!cur)
        {
            return pre;
        }
        ListNode *temp = cur->next;
        cur->next = pre;
        return recursion(cur, temp);
    }
    ListNode *reverseList(ListNode * head)
    {
        return recursion(nullptr, head);
    }

    // 反转链表 递归2

    ListNode *reverseList(ListNode * head)
    {
        if (!head)
        {
            return head;
        }
        else if (!head->next)
        {
            return head;
        }
        ListNode *temp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return head
    }

    // 两两交换链表中的节点
    ListNode *swapPairs(ListNode * head)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        while (cur->next && cur->next->next)
        {
            ListNode *temp1 = cur->next->next->next;
            ListNode *temp2 = cur->next->next;
            cur->next->next->next = cur->next;
            cur->next->next = temp1;
            cur->next = temp2;
            cur = cur->next->next;
        }
        return dummyNode->next;
    }

    // 删除链表的倒数第n个节点
    ListNode *removeNthFromEnd(ListNode * head, int n)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *fast = dummy, slow = dummy;
        dummy->next = head;
        while (n--)
        {
            fast = fast->next;
        }
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return dummy->next;
    }

    // 链表相交
    ListNode *getIntersectionNode(ListNode * headA, ListNode * headB)
    {
        int sizea = 0, sizeb = 0;
        ListNode *tempa = headA, *tempb = headB;
        while (tempa)
        {
            tempa = tempa->next;
            sizea++;
        }
        while (tempb)
        {
            tempb = tempb->next;
            sizeb++;
        }

        tempa = headA;
        tempb = headB;
        if (sizeb > sizea)
        {
            ListNode *temp = tempa;
            tempa = tempb;
            tempb = temp;
            int temp2 = sizea;
            sizea = sizeb;
            sizeb = temp2;
        }

        int n = sizea - sizeb;
        while (n--)
        {
            tempa = tempa->next;
        }

        while (tempa)
        {
            if (tempa == tempb)
            {
                return tempa;
            }
            tempa = tempa->next;
            tempb = tempb->next;
        }

        return nullptr;
    }

    // 环形链表找入口
    ListNode *detectCycle(ListNode * head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head;
        ListNode *temp = dummy;
        while (cur)
        {
            for (temp = dummy; temp != cur; temp = temp->next)
            {
                if (cur->next == temp->next)
                {
                    return temp->next;
                }
            }
            cur = cur->next;
        }
        return nullptr;
    }

    // 环形链表入口 (双指针法)
    ListNode *detectCycle(ListNode * head)
    {
        ListNode *fast = head, *slow = head;
        if (!head)
        {
            return nullptr;
        }
        if (head->next == head)
        {
            return head;
        }
        else if (!head->next)
        {
            return nullptr;
        }
        fast = fast->next->next;
        slow = slow->next;
        while (fast != slow && fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!fast || !fast->next)
        {
            return nullptr;
        }
        else
        {
            ListNode *temp1 = head;
            ListNode *temp2 = fast;
            while (temp1 != temp2)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1;
        }
    }

    // 有效的字母异位词
    bool isAnagram(string s, string t)
    {
        int record[26] = {0};
        for (char c : s)
        {
            record[c - 97]++;
        }
        for (char c : t)
        {
            record[c - 97]--;
        }
        for (int e : record)
        {
            if (e != 0)
            {
                return false;
            }
        }
        return true;
    }

    // 赎金信
    bool canConstruct(string ransomNote, string magazine)
    {
        int record[26] = {0};
        for (char c : magazine)
        {
            record[c - 97]++;
        }
        for (char c : ransomNote)
        {
            record[c - 97]--;
        }
        for (int e : record)
        {
            if (e < 0)
            {
                return false;
            }
        }
        return true;
    }

    // 两个数组交集
    vector<int> intersection(vector<int> & nums1, vector<int> & nums2)
    {
        unordered_set<int> result;
        unordered_set<int> set(nums1.begin(), nums1.end());
        for (int e : nums2)
        {
            if (set.find(e) != set.end())
            {
                result.insert(e);
            }
        }
        return vector<int>(result.begin(), result.end());
    }

    // 快乐数
    bool isHappy(int n)
    {
        unordered_set<int> sumset;
        while (1)
        {
            int sum = getSum(n);
            if (sum == 1)
            {
                return true;
            }
            if (sumset.find(sum) != sumset.end())
            {
                return false;
            }
            sumset.insert(sum);
            n = sum;
        }
    }
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int temp = n % 10;
            sum += (temp * temp);
            n /= 10;
        }
        return sum;
    }

    // 两数相加
    vector<int> twoSum(vector<int> & nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = map.find(target - nums[i]);
            if (it != map.end())
            {
                return {i, it->second};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }

    // 四数相加
    int fourSumCount(vector<int> & nums1, vector<int> & nums2, vector<int> & nums3, vector<int> & nums4)
    {
        int n = nums1.size();
        int count = 0;
        unordered_map<int, int> map; // sum and count
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto it = map.find(nums1[i] + nums2[j]);
                if (it != map.end())
                {
                    it->second++;
                }
                else
                {
                    map.insert(pair(nums1[i] + nums2[j], 1));
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                auto it = map.find(0 - (nums3[k] + nums4[l]));
                if (it != map.end())
                {
                    count += it->second;
                }
            }
        }
        return count;
    }

    // 三数之和
    vector<vector<int>> threeSum(vector<int> & nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }

    // 反转字符串
    void reverseString(vector<char> & s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            char temp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = temp;
        }
    }

    // 反转字符串2
    void reverse(vector<char> & s, int h, int t)
    {
        if (h == t)
        {
            return;
        }
        int n = t + h;
        for (int i = h; i < (n + 1) / 2; i++)
        {
            swap(s[i], s[n - i]);
        }
    }
    string reverseStr(string s, int k)
    {
        int size = s.size();
        int i = 0;
        while (1)
        {
            if ((size - i) < k)
            {
                reverse(s, i, size - 1);
                break;
            }
            else if ((size - i) < 2 * k && (size - 1) >= k)
            {
                reverse(i, i + k - 1);
                break;
            }
            else
            {
                reverse(i, i + k - 1);
                i = i + 2 * k;
                if (i >= size)
                {
                    break;
                }
            }
        }
        return s;
    }

    // 替换空格
    string replaceSpace(string s)
    {
        vector<char> res;
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                res[k++] = '%';
                res[k++] = '2';
                res[k++] = '0';
            }
            else
            {
                res[k++] = s[i];
            }
        }
        return string(res.begin(), res.end());
    }
    // 替换空格双指针法
    string replaceSpace(string s)
    {
        int count = 0;
        int fast = s.size() - 1;
        for (char c : s)
        {
            if (c == ' ')
            {
                count++;
            }
        }
        if (!count)
        {
            return s;
        }
        s.resize(s.size() + count * 2);
        int slow = s.size() - 1;
        while (fast != slow)
        {
            if (s[fast] != ' ')
            {
                s[slow--] = s[fast--];
            }
            else
            {
                s[slow--] = '0';
                s[slow--] = '2';
                s[slow--] = '%';
                fast--;
            }
        }
        return s;
    }

    // 左旋转字符串
    string reverseLeftWords(string s, int n)
    {
        reverse(s.begin(), s.end());
        int i = s.size();
        while (n--)
        {
            i--;
        }
        reverse(s.begin(), s.begin() + i);
        reverse(s.begin() + i, s.end());
        return s;
    }

    // 找出字符串中第一个匹配项的下标
    int strStr(string haystack, string needle)
    {
        int t = 0;
        int s = 0;
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        while (s < haystack.size())
        {
            if (needle[t] == haystack[s])
            {
                if (t == needle.size() - 1)
                {
                    return s - t;
                }
                t++;
                s++;
            }
            else
            {
                s = s - t + 1;
                t = 0;
            }
        }
        return -1;
    }

    // 重复的子字符串
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 1)
        {
            return false;
        }
        int count = 1;
        int i, k;
        while (count <= s.size() / 2)
        {
            i = 0;
            for (k = count; k < s.size(); k++, i = (i + 1) % count)
            {
                if (s[i] != s[k])
                {
                    break;
                }
            }
            if (k == s.size() && !i)
            {
                return true;
            }
            count++;
        }
        return false;
    }
    // 移动匹配解法
    bool repeatedSubstringPattern(string s)
    {
        string s2 = s + s;
        s2.erase(s2.begin());
        s2.erase(s2.end() - 1);
        if (s2.find(s))
        {
            return true;
        }
        return false;
    }

    // 232 用栈实现队列
    class MyQueue
    {
    public:
        stack<int> stackIn, stackOut;
        MyQueue()
        {
        }

        void push(int x)
        {
            stackIn.push(x);
        }

        int pop()
        {
            if (stackOut.empty())
            {
                while (!stackIn.empty())
                {
                    stackOut.push(stackIn.top());
                    stackIn.pop();
                }
            }
            int res = stackOut.top();
            stackOut.pop();
            return res;
        }

        int peek()
        {
            int res = this->pop();
            stackOut.push(res);
            return res;
        }

        bool empty()
        {
            return stackIn.empty() && stackOut.empty();
        }
    };

    // 225 用队列实现栈
    class MyStack
    {
    public:
        deque<int> que1, que2;
        MyStack()
        {
        }

        void push(int x)
        {
            if (que2.empty())
            {
                que1.push_back(x);
            }
            else
            {
                que2.push_back(x);
            }
        }

        int pop()
        {
            int res;
            if (que2.empty())
            {
                while (!que1.empty())
                {
                    res = que1.front();
                    que1.pop_front();
                    if (que1.empty())
                    {
                        return res;
                    }
                    else
                    {
                        que2.push_back(res);
                    }
                }
            }
            else
            {
                while (!que2.empty())
                {
                    res = que2.front();
                    que2.pop_front();
                    if (que2.empty())
                    {
                        return res;
                    }
                    else
                    {
                        que1.push_back(res);
                    }
                }
            }
            return res;
        }

        int top()
        {
            int res = this->pop();
            this->push(res);
            return res;
        }

        bool empty()
        {
            return que1.empty() && que2.empty();
        }
    };
    // 队列实现栈第二种
    class MyStack
    {
    public:
        deque<int> que;
        MyStack()
        {
        }

        void push(int x)
        {
            que.push_back(x);
        }

        int pop()
        {
            int size = que.size();
            int res;
            while (size--)
            {
                res = que.front();
                que.pop_front();
                if (size)
                {
                    que.push_back(res);
                }
            }
            return res;
        }

        int top()
        {
            int res = this->pop();
            que.push_back(res);
            return res;
        }

        bool empty()
        {
            return que.empty();
        }
    };

    // 20 有效的括号
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<int> stack;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                {
                    return false;
                }
                char top = stack.top();
                if (c - top != 1 && c - top != 2)
                {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }

    // 1047.删除字符串中的所有相邻重复项
    string removeDuplicates(string s)
    {
        if (!s.size() || s.size() == 1)
        {
            return s;
        }
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (stack.empty() || stack.top() != s[i])
            {
                stack.push(s[i]);
            }
            else
            {
                stack.pop();
            }
        }
        string res;
        while (!stack.empty())
        {
            res.push(stack.top());
            stack.pop();
        }
        return res;
    }

    // 150. 逆波兰表达式求值
    int evalRPN(vector<string> & tokens)
    {
        stack<long long> stack;
        for (string token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                long long operand1 = (stack.top());
                stack.pop();
                long long operand2 = (stack.top());
                stack.pop();
                if (token == "+")
                {
                    stack.push((operand2 + operand1));
                }
                if (token == "-")
                {
                    stack.push((operand2 - operand1));
                }
                if (token == "*")
                {
                    stack.push((operand2 * operand1));
                }
                if (token == "/")
                {
                    stack.push((operand2 / operand1));
                }
            }
            else
            {
                stack.push(stoll(token));
            }
        }
        return (stack.top());
    }

    // 239. 滑动窗口最大值
    int getMax(deque<int> & que)
    {
        int max = INT_MIN;
        for (auto it = que.begin(); it != que.end(); it++)
        {
            max = (*it > max) ? *it : max;
        }
        return max;
    }
    vector<int> maxSlidingWindow(vector<int> & nums, int k)
    {
        deque<int> que;
        int n = nums.size() - k;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            que.push_back(nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            res.push_back(getMax(que));
            que.pop_front();
            que.push_back(i + k);
        }
        return res;
    }

    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    // 144二叉树前序遍历
    void traversal(TreeNode * cur, vector<int> & result)
    {
        if (!cur)
        {
            return;
        }
        result.push_back(cur->val);
        traversal(cur->left, result);
        traversal(cur->right, result);
    }
    vector<int> preorderTraversal(TreeNode * root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    // 144迭代法
    vector<int> preorderTraversal(TreeNode * root)
    {
        if (!root)
        {
            return {};
        }
        stack<TreeNode *> stack;
        vector<int> result;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *cur = stack.top();
            result.push_back(cur->val);
            stack.pop();
            if (cur->right)
            {
                stack.push(cur->right);
            }
            if (cur->left)
            {
                stack.push(cur->left);
            }
        }
        return result;
    }
    // 145后序遍历
    void traversal(TreeNode * cur, vector<int> & result)
    {
        if (!cur)
        {
            return;
        }
        traversal(cur->left, result);
        traversal(cur->right, result);
        result.push_back(cur->val);
    }

    // 94二叉树中序遍历(迭代)
    vector<int> inorderTraversal(TreeNode * root)
    {
        if (!root)
        {
            return {};
        }
        stack<TreeNode *> stack;
        vector<int> result;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *cur = stack.top();
            if (cur->left)
            {
                stack.push(cur->left);
                cur->left = nullptr;
            }
            else
            {
                result.push_back(cur->val);
                stack.pop();
                if (cur->right)
                {
                    stack.push(cur->right);
                    cur->right = nullptr;
                }
            }
        }
        return result;
    }
    // 145二叉树后序遍历
    vector<int> postorderTraversal(TreeNode * root)
    {
        if (!root)
        {
            return {};
        }
        stack<TreeNode *> stack;
        vector<int> result;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *cur = stack.top();
            if (!cur->left && !cur->right)
            {
                result.push_back(stack.top()->val);
                stack.pop();
            }
            if (cur->right)
            {
                stack.push(cur->right);
                cur->right = nullptr;
            }
            if (cur->left)
            {
                stack.push(cur->left);
                cur->left = nullptr;
            }
        }
        return result;
    }
    // 102二叉树的层序遍历
    vector<vector<int>> levelOrder(TreeNode * root)
    {
        if (!root)
        {
            return {};
        }
        deque<TreeNode *> que;
        vector<vector<int>> result;
        que.push_back(root);
        while (!que.empty())
        {
            vector<int> temp;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = que.front();
                temp.push_back(front->val);
                que.pop_front();
                if (front->left)
                {
                    que.push_back(front->left);
                }
                if (front->right)
                {
                    que.push_back(front->right);
                }
            }
            result.push_back(temp);
        }
        return result;
    }

    // 226 翻转二叉树
    TreeNode *invertTree(TreeNode * root)
    {
        deque<TreeNode *> que;
        que.push_back(root);
        while (!que.empty())
        {
            TreeNode *front = que.front();
            que.pop_front();
            if (!front)
            {
                continue;
            }
            TreeNode *temp = front->left;
            front->left = front->right;
            front->right = temp;
            que.push_back(front->left);
            que.push_back(front->right);
        }
        return root;
    }
    // 递归法
    TreeNode *invertTree(TreeNode * root)
    {
        if (!root || !root->left && !root->right)
        {
            return root;
        }
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    // 迭代法
    TreeNode *invertTree(TreeNode * root)
    {
        stack<TreeNode *> stack;
        if (root)
        {
            stack.push(root);
        }
        while (!stack.empty())
        {
            TreeNode *top = stack.top();
            stack.pop();
            if (!top || !top->left && !top->right)
            {
                continue;
            }
            swap(top->left, top->right);
            stack.push(top->left);
            stack.push(top->right);
        }
        return root;
    }

    // 101.对称二叉树
    bool recursive(vector<TreeNode *> layer)
    {
        int size = layer.size();
        bool b = true;
        bool e = false;
        for (int i = 0; i < size / 2; i++)
        {
            if (layer[i] || layer[size - i - 1])
            {
                e = true;
            }
            if (!layer[i] && !layer[size - i - 1])
            {
            }
            else if (!layer[i] && layer[size - i - 1] || layer[i] && !layer[size - i - 1] || layer[i]->val != layer[size - i - 1]->val)
            {
                b = false;
            }
        }
        if (!b)
        {
            return false;
        }
        if (!e)
        {
            return true;
        }
        vector<TreeNode *> temp;
        for (int i = 0; i < size; i++)
        {
            if (layer[i])
            {
                temp.push_back(layer[i]->left);
                temp.push_back(layer[i]->right);
            }
            else
            {
                temp.push_back(nullptr);
                temp.push_back(nullptr);
            }
        }
        return recursive(temp);
    }
    bool isSymmetric(TreeNode * root)
    {
        if (!root->left && !root->right)
        {
            return true;
        }
        vector<TreeNode *> layer;
        layer.push_back(root->left);
        layer.push_back(root->right);
        return recursive(layer);
    }
    // 递归法2
    bool compare(TreeNode * left, TreeNode * right)
    {
        if (!left && !right)
        {
            return true;
        }
        if (!left && right || left && !right || left->val != right->val)
        {
            return false;
        }

        return compare(left->right, right->left) && compare(left->left, right->right);
    }
    bool isSymmetric(TreeNode * root)
    {
        return compare(root->left, root->right);
    }
    // 迭代法
    bool isSymmetric(TreeNode * root)
    {
        deque<TreeNode *> que;
        que.push_back(root->left);
        que.push_back(root->right);
        while (!que.empty())
        {
            TreeNode *left = que.front();
            que.pop_front();
            TreeNode *right = que.front();
            que.pop_front();
            if (!left && !right)
            {
                continue;
            }
            else if (!left || !right || left->val != right->val)
            {
                return false;
            }
            que.push_back(left->left);
            que.push_back(right->right);
            que.push_back(left->right);
            que.push_back(right->left);
        }
        return true;
    }
    // 使用栈迭代
    bool isSymmetric(TreeNode * root)
    {
        stack<TreeNode *> stack;
        stack.push(root->left);
        stack.push(root->right);
        while (!stack.empty())
        {
            TreeNode *right = stack.top();
            stack.pop();
            TreeNode *left = stack.top();
            stack.pop();
            if (!left && !right)
            {
                continue;
            }
            if (!left || !right || left->val != right->val)
            {
                return false;
            }
            stack.push(right->right);
            stack.push(left->left);
            stack.push(right->left);
            stack.push(left->right);
        }
        return true;
    }

    // 104二叉树的最大深度
    int maxDepth(TreeNode * root)
    {
        if (!root)
        {
            return 0;
        }
        int a = maxDepth(root->left);
        int b = maxDepth(root->right);
        return (a > b ? a : b) + 1;
    }
    // 迭代法
    int maxDepth(TreeNode * root)
    {
        deque<TreeNode *> que;
        if (root)
        {
            que.push_back(root);
        }
        int count = 0;
        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                TreeNode *front = que.front();
                que.pop_front();
                if (front->left)
                    que.push_back(front->left);
                if (front->right)
                    que.push_back(front->right);
            }
            count++;
        }
        return count;
    }

    // 559 n叉树的最大深度
    int maxDepth(Node * root)
    {
        if (!root)
        {
            return 0;
        }
        int depth = 0;
        for (Node *n : root->children)
        {
            int m = maxDepth(n);
            depth = m > depth ? m : depth;
        }
        return depth + 1;
    }
    // 迭代法
    int maxDepth(Node * root)
    {
        if (!root)
        {
            return 0;
        }
        deque<Node *> que;
        que.push_back(root);
        int count = 0;
        while (!que.empty())
        {
            count++;
            int size = que.size();
            while (size--)
            {
                Node *front = que.front();
                que.pop_front();
                for (Node *n : front->children)
                {
                    if (n)
                        que.push_back(n);
                }
            }
        }
        return count;
    }

    // 111二叉树的最小深度
    int minDepth(TreeNode * root)
    {
        if (!root)
        {
            return 0;
        }
        if (root->left && root->right)
        {
            int a = minDepth(root->left);
            int b = minDepth(root->right);
            return (a < b ? a : b) + 1;
        }
        if (root->left)
        {
            return minDepth(root->left) + 1;
        }
        if (root->right)
        {
            return minDepth(root->right) + 1;
        }
        return 1;
    }
    // 迭代法
    int minDepth(TreeNode * root)
    {
        if (!root)
        {
            return 0;
        }
        deque<TreeNode *> que;
        que.push_back(root);
        int count = 0;
        while (!que.empty())
        {
            int size = que.size();
            count++;
            while (size--)
            {
                TreeNode *front = que.front();
                que.pop_front();
                if (!front->left && !front->right)
                {
                    return count;
                }
                if (front->left)
                {
                    que.push_back(front->left);
                }
                if (front->right)
                {
                    que.push_back(front->right);
                }
            }
        }
        return count;
    }

    // 222完全二叉树的节点个数
    int countNodes(TreeNode * root)
    {
        if (!root)
        {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    // 迭代法
    int countNodes(TreeNode * root)
    {
        if (!root)
        {
            return 0;
        }
        deque<TreeNode *> que;
        int count = 0;
        que.push_back(root);
        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                TreeNode *front = que.front();
                que.pop_front();
                count++;
                if (front->left)
                {
                    que.push_back(front->left);
                }
                if (front->right)
                {
                    que.push_back(front->right);
                }
            }
        }
        return count;
    }
    // 222 完全二叉树的节点个数(利用完全二叉树特性的解法)
    int countNodes(TreeNode * root)
    {
        if (!root)
        {
            return 0;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftLength = 0, rightLength = 0;
        while (left)
        {
            left = left->left;
            leftLength++;
        }
        while (right)
        {
            right = right->right;
            rightLength++;
        }
        if (rightLength == leftLength)
        {
            return (1 << (leftLength + 1)) - 1;
        }
        else
        {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }

    // 110 平衡二叉树
    int getHeight(TreeNode * node)
    {
        if (!node)
        {
            return 0;
        }
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
    bool isBalanced(TreeNode * root)
    {
        if (!root)
        {
            return true;
        }
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
        {
            return false;
        }
        else
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
    // 迭代法
    bool isBalanced(TreeNode * root)
    {
        stack<TreeNode *> stack;
        if (!root)
        {
            return true;
        }
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *top = stack.top();
            stack.pop();
            if (abs(getHeight(top->left) - getHeight(top->right)) > 1)
            {
                return false;
            }
            else
            {
                if (top->left)
                    stack.push(top->left);
                if (top->right)
                    stack.push(top->right);
            }
        }
        return true;
    }

    // 257.二叉树的所有路径
    void traversal(TreeNode * cur, vector<int> & path, vector<string> & result)
    {

        if (!cur->left && !cur->right)
        {
            string str;
            for (int i = 0; i < path.size(); i++)
            {
                str += to_string(path[i]);
                str += "->";
            }
            str += to_string(cur->val);
            result.push_back(str);
            return;
        }

        path.push_back(cur->val);
        if (cur->left)
        {
            traversal(cur->left, path, result);
        }
        if (cur->right)
        {
            traversal(cur->right, path, result);
        }
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode * root)
    {
        vector<string> result;
        vector<int> path;
        traversal(root, path, result);
        return result;
    }

    // 左叶子之和
    int sumOfLeftLeaves(TreeNode * root)
    {
        if (!root->left && !root->right)
        {
            return 0;
        }
        stack<TreeNode *> stack;
        stack.push(root);
        int sum = 0;
        while (!stack.empty())
        {
            TreeNode *top = stack.top();
            stack.pop();
            if (top->left)
            {
                if (!top->left->left && !top->left->right)
                {
                    sum += top->left->val;
                }
                else
                {
                    stack.push(top->left);
                }
            }
            if (top->right)
            {
                if (top->right->left || top->right->right)
                {
                    stack.push(top->right);
                }
            }
        }
        return sum;
    }
    // 递归法
    int sumOfLeftLeaves(TreeNode * root)
    {
        if (!root || !root->left && !root->right)
        {
            return 0;
        }
        if (root->left)
        {
            if (!root->left->left && !root->left->right)
            {
                return root->left->val + sumOfLeftLeaves(root->right);
            }
            else
            {
                return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
            }
        }
        else
        {
            return sumOfLeftLeaves(root->right);
        }
    }

    // 513找树左下角的值 递归法
    int getHeight(TreeNode * node)
    {
        if (!node)
        {
            return 0;
        }
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
    int findBottomLeftValue(TreeNode * root)
    {
        if(!root->left&&!root->right){
            return root->val;
        }
        if(root->left){
            if(root->left->left||root->left->right){
                if(getHeight(root->left)<getHeight(root->right)){
                    return findBottomLeftValue(root->right);
                }
                return findBottomLeftValue(root->left);
            }else{
                if(root->right&&(root->right->left||root->right->right)){
                    return findBottomLeftValue(root->right);
                }else{
                    return findBottomLeftValue(root->left);
                }
            }
        }else{
            return findBottomLeftValue(root->right);
        }

    }
    // 层序遍历(迭代法)
    int findBottomLeftValue(TreeNode * root)
    {
        deque<TreeNode *> que;
        que.push_back(root);
        int result = 0;
        while (!que.empty())
        {
            int size = que.size();
            int i=size;
            while (i--)
            {
                TreeNode *front = que.front();
                que.pop_front();
                if(i==size-1)result = front->val;
                if (front->left)
                {
                    que.push_back(front->left);
                }
                if (front->right)
                {
                    que.push_back(front->right);
                }
            }
        }
        return result;
    }
}