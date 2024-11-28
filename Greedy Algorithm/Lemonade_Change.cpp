class Solution
{
public:
  // Function to determine if we can provide change for every customer
  // `bills` represents the list of bills each customer pays with
  bool lemonadeChange(vector<int> &bills)
  {
    // Initialize counters for $5 and $10 bills
    int five = 0, ten = 0;

    // Iterate over each bill in the `bills` vector
    for (int i = 0; i < bills.size(); i++)
    {
      // If the customer pays with a $5 bill
      if (bills[i] == 5)
      {
        // Increment the count of $5 bills
        five += 1;
      }
      // If the customer pays with a $10 bill
      else if (bills[i] == 10)
      {
        // Check if we have a $5 bill to give as change
        if (five)
        {
          // Use one $5 bill for change
          five -= 1;
          // Increment the count of $10 bills
          ten += 1;
        }
        else
        {
          // If no $5 bill is available, return false
          return false;
        }
      }
      // If the customer pays with a $20 bill
      else
      {
        // Prefer to give one $10 and one $5 bill as change if possible
        if (ten && five)
        {
          ten -= 1;
          five -= 1;
        }
        // Otherwise, give three $5 bills as change if possible
        else if (five >= 3)
        {
          five -= 3;
        }
        else
        {
          // If neither option is possible, return false
          return false;
        }
      }
    }
    // If we successfully provided change for all customers, return true
    return true;
  }
};