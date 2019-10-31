/***************************************************************************************

	Author: Ali Faisal
	Topic: Longest Common Subsequence - Dynamic Programming
	Features: Give matched LCS string by backtracking and its length.
	
****************************************************************************************/

#include <iostream>

using namespace std;

int LCS(); // getting scores on the table and knowing the length of LCS string at M[m][n]
void createTable(); // creating both character and score table
void printTable(); // printing both tables
void getLCS(int i, int j);	// printing the LCS string

string A = "BDCABA", B = "ABCBDAB", matched = "";
int **M;	// score table
char **P;	// character table for backtrack

int main()
{
	cout<<"String1: "<<A<<"\nString2: "<<B<<"\n\n";
	
	createTable();
	
	cout<<"Length Of LCS: "<<LCS();
	
	printTable();
	
	getLCS(A.length(), B.length());
	//cout<<"\n\nLCS: "<<matched<<"\n\n";
	
	cout<<"\n\nLongest Common Subsequence: ";
	for(int i=matched.length()-1; i>=0; i--)
	{
		cout<<matched[i];	// printing sequence by reversing because the sequence returned is reversed.
	}
	
	cout<<"\n\n";
}

int LCS()
{
	for(int i=1; i<=A.length(); i++)
	{
		for(int j=1; j<=B.length(); j++)
		{
			if(A[i-1] == B[j-1]) // indexing of strings is 0 based so subtracting -1 from i and j
			{
				M[i][j] = 1 + M[i-1][j-1];
				P[i][j] = 'D';
			}
			else
			{
				if(M[i-1][j] >= M[i][j-1])
				{
					P[i][j] = 'U';
					M[i][j] = M[i-1][j];
				}
				else
				{
					P[i][j] = 'L';
					M[i][j] = M[i][j-1];
				}
			}
		}
	}
	
	return M[A.length()][B.length()];	// returning length of LCS string
}

void getLCS(int i, int j) // backtracking from P[m][n]
{
	if(i == 0 || j == 0)
	{
		return;
	}
	else if(P[i][j] == 'D')
	{
		matched+=A[i-1];	// appends matched sequence bottom up hence the esult will be reversed. // i-1 because indexing is zero based
		getLCS(i-1, j-1);
	}
	else if(P[i][j] == 'U')
	{
		getLCS(i-1, j);
	}
	else if(P[i][j] == 'L')
	{
		getLCS(i, j-1);
	}
}

void createTable()
{
	M = new int*[A.length()+1];
	for(int i=0; i<=A.length(); i++)
	{
		M[i] = new int[B.length()+1];
	}
	
	for(int i=0; i<=A.length(); i++)
	{
		for(int j=0; j<=B.length(); j++)
		{
			M[i][j] = 0;
		}
	}
	
	P = new char*[A.length()+1];
	for(int i=0; i<=A.length(); i++)
	{
		P[i] = new char[B.length()+1];
	}
	
	for(int i=0; i<=A.length(); i++)
	{
		for(int j=0; j<=B.length(); j++)
		{
			P[i][j] = '_';
		}
	}
}

void printTable()
{
	cout<<"\n\nScore Table: \n\n";
	for(int i=0; i<=A.length(); i++)
	{
		for(int j=0; j<=B.length(); j++)
		{
			cout<<M[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
	
	cout<<"\n\nCharacter Table: \n\n";
	for(int i=0; i<=A.length(); i++)
	{
		for(int j=0; j<=B.length(); j++)
		{
			cout<<P[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
}
