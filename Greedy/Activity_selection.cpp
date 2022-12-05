/**
Greedy:
Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. 
Greedy algorithms are used for optimization problems. 

An optimization problem can be solved using Greedy if the problem has the following property: 

At every step, we can make a choice that looks best at the moment, and we get the optimal solution to the complete problem.

If a Greedy Algorithm can solve a problem, then it generally becomes the best method to solve that problem as the Greedy algorithms are 
in general more efficient than other techniques like Dynamic Programming. But Greedy algorithms cannot always be applied.
 For example, the Fractional Knapsack problem can be solved using Greedy, but 0-1 Knapsack cannot be solved using Greedy.
 */
/**
 * Question:
Given N activities with their start and finish day given in array start[ ] and end[ ]. 
Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// void printMaxActivities(int s[], int f[], int n)
// {
//     int i, j;
 
//     cout << "Following activities are selected" << endl;
 
//     // The first activity always gets selected
//     i = 0;
//     cout << i << " ";
 
//     // Consider rest of the activities
//     for (j = 1; j < n; j++) {
//         // If this activity has start time greater than or
//         // equal to the finish time of previously selected
//         // activity, then select it
//         if (s[j] >= f[i]) {
//             cout << j << " ";
//             i = j;
//         }
//     }
// }
 
// // Driver code
// int main()
// {
//     int s[] = { 1, 3, 0, 5, 8, 5 };
//     int f[] = { 2, 4, 6, 7, 9, 9 };
//     int n = sizeof(s) / sizeof(s[0]);
 
//     // Function call
//     printMaxActivities(s, f, n);
//     return 0;
// }

// using structures

struct Activitiy {
    int start, finish;
};
 
// A utility function that is used for sorting
// activities according to finish time
bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}
 
// Returns count of the maximum set of activities that can
// be done by a single person, one at a time.
void printMaxActivities(Activitiy arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr + n, activityCompare);
 
    cout << "Following activities are selected :\n";
 
    // The first activity always gets selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish
         << ")";
 
    // Consider rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (arr[j].start >= arr[i].finish) {
            cout << ", (" << arr[j].start << ", "
                 << arr[j].finish << ")";
            i = j;
        }
    }
}
 
// Driver code
int main()
{
    Activitiy arr[] = { { 5, 9 }, { 1, 2 }, { 3, 4 },
                        { 0, 6 }, { 5, 7 }, { 8, 9 } };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    printMaxActivities(arr, n);
    return 0;
}

// using queue 
/*

void SelectActivities(vector<int> s, vector<int> f)
{
	// Vector to store results.
	vector<pair<int, int> > ans;

	// Minimum Priority Queue to sort activities in
	// ascending order of finishing time (f[i]).

	priority_queue<pair<int, int>, vector<pair<int, int> >,
				greater<pair<int, int> > >
		p;

	for (int i = 0; i < s.size(); i++) {
		// Pushing elements in priority queue where the key
		// is f[i]
		p.push(make_pair(f[i], s[i]));
	}

	auto it = p.top();
	int start = it.second;
	int end = it.first;
	p.pop();
	ans.push_back(make_pair(start, end));

	while (!p.empty()) {
		auto itr = p.top();
		p.pop();
		if (itr.second >= end) {
			start = itr.second;
			end = itr.first;
			ans.push_back(make_pair(start, end));
		}
	}
	cout << "Following Activities should be selected. "
		<< endl
		<< endl;

	for (auto itr = ans.begin(); itr != ans.end(); itr++) {
		cout << "Activity started at " << (*itr).first
			<< " and ends at " << (*itr).second << endl;
	}
}

// Driver code
int main()
{
	vector<int> s = { 1, 3, 0, 5, 8, 5 };
	vector<int> f = { 2, 4, 6, 7, 9, 9 };

	// Function call
	SelectActivities(s, f);

	return 0;
}
*/
