// C++ program to check if 
// given date is valid or not and ISBN modulus 11
#include<iostream>
#include<stdlib.h>

using namespace std;

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1000;

class newValidation
{
	public:
		bool validMode11(long long int ISBN);
        bool validDate(int dd, int mm,int yyyy);
        bool isLeap(int yyyy);
		
};


// Returns true if 
// given year is valid.
bool newValidation::isLeap(int yyyy)
{
// Return true if year 
// is a multiple pf 4 and
// not multiple of 100.
// OR year is multiple of 400.
return (((yyyy % 4 == 0) && 
         (yyyy % 100 != 0)) ||
         (yyyy % 400 == 0));
}


// Returns true if given
// year is valid or not.
bool newValidation::validDate(int dd, int mm, int yyyy)
{
    // If year, month and day 
    // are not in given range
    if (yyyy > MAX_VALID_YR || 
        yyyy < MIN_VALID_YR)
    return false;
    if (mm < 1 || mm > 12)
    return false;
    if (dd < 1 || dd > 31)
    return false;
 
    // Handle February month 
    // with leap year
    if (mm == 2)
    {
        if (isLeap(yyyy))
        return (dd <= 29);
        else
        return (dd <= 28);
    }
 
    // Months of April, June, 
    // Sept and Nov must have 
    // number of days less than
    // or equal to 30.
    if (mm == 4 || mm == 6 ||
        mm == 9 || mm == 11)
        return (dd <= 30);
 
    return true;
}



bool newValidation::validMode11(long long int ISBN	)
{
	int X=10;		//For ISBN
	cout<<"Enter the ISBN"<<endl;
	cin>>ISBN;
	int array[10]; //This array will store ISBN(We convert the long long int into array)
	for(int i=9;i>=0;i--)
	{
		array[i]=ISBN%10;
		ISBN /=10;
	}
	int array1[10]={10,9,8,7,6,5,4,3,2,1};
	int array2[10];	//This array will store the final value for checking of modulus 11

	for(int i=0;i<10;i++)
	{
		array2[i]=array[i]*array1[i];
	}
	int sum=0;
	for(int i=0;i<10;i++)
	{
		sum=sum+array2[i];		//Adding values if array2
	}
	if(sum%11==0)
		return true;
	else
		return false;
		
}




int main(void)
{
	int dd,mm,yyyy;
	long long int ISBN;
	newValidation object;
	int n;
	while(1)
	{
		cout<<"Menu"<<endl;
		cout<<"1.Validate modulus 11 number"<<endl;
		cout<<"2.Validate date"<<endl;
		cout<<"3.Quit"<<endl;
		cout<<"Enter menu option"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:	long long int ISBN;					//Modulus 11
					if(object.validMode11(ISBN)==1)
					{
						cout<<"Valid Modulus 11 number"<<endl;
						cout<<"press RETURN to continue"<<endl;
    					while(cin.get()=='\n')
    					{
    						if(cin.get()=='\n')
        						break;
    						else
       							cout<<"I meant ONLY the RETURN key... Oh well"<<endl;
    					}
    					break;
       				}

					else
					{
						cout<<"Invlid Modulud 11 number"<<endl;
						cout<<"press RETURN to continue"<<endl;
						while(cin.get()=='\n')
    					{
    						if(cin.get()=='\n')
        						break;
    						else
       							cout<<"I meant ONLY the RETURN key... Oh well"<<endl;
    					}
    					break;
					}

			case 2:				//date validity
					cout<<"Enter the date(dd-mm-yyyy): "<<endl;
    				cin>>dd>>mm>>yyyy;

    				object.validDate(dd,mm,yyyy);
    				object.validDate(dd,mm,yyyy)? cout << "Valid Date\n" :
                          						 cout << "Invalid Date\n";
                    cout<<"press RETURN to continue"<<endl;
                    while(cin.get()=='\n')
    					{
    						if(cin.get()=='\n')
        						break;
    						else
       							cout<<"I meant ONLY the RETURN key... Oh well"<<endl;
    					}
    					break;

            case 3:
            		abort();

		}
	}
	
}