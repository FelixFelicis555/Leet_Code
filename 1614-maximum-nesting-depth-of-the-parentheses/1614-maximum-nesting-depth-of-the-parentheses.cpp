class Solution {
public:
    int maxDepth(string s) {
       int current_max = 0; // current count // To check validity of parenthesis string
	int max = 0; // overall maximum count
	int n = s.length();

	// Traverse the input string
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			current_max++;

			// update max if required
			if (current_max > max)
				max = current_max;
		}
		else if (s[i] == ')')
		{
			if (current_max > 0)
				current_max--;
			else
				return -1;
		}
	}

	// finally check for unbalanced string
	if (current_max != 0)
		return -1;

	return max; 
    }
};