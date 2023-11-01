#include <iostream>
using namespace std;
int main() {
  //   // cout << "Hello World!\n";
  //   // // int n;

  //   // if(cout<<"love")
  //   // {
  //   //   cout<<"babbar"<<endl;
  //   // }
  //   // for(int row = 0; row < 3; row++)
  //   //   {
  //   //     for(int col = 0; col <5; col++)
  //   //       {
  //   //         cout<<" * ";
  //   //       }
  //   //     cout<<endl;
  //   //   }
  //   // int n;
  //   // cin >> n;
  //   // for (int row = 0; row < n; row++) {
  //   //   for (int col = 0; col < row + 1; col++) {
  //   //     cout << col + 1;
  //   //   }
  //   //   cout << endl;
  //   // }

  //   //    *
  //   //   * *
  //   // *  *  *
  // // int n;
  // //   cin>>n;
    
  //         // *
  // //   //   * *
  // //   // *  *  *
  // //   // *  *  *
  // //   //  *   *
  // //   //    *
  // int n;
  // cin >> n;
  // for (int row = 0; row < n; row++) {
  //   for (int col = 0; col < (n - row-1); col++) {
  //     cout << " ";
  //   }
  //   for (int i = 0; i < (row + 1); i++) {
  //     cout << "* ";
  //   }
  //   cout << endl;
  // }
  // for(int row = 0; row<n; row++)
  //     {
  //       for(int col = 0; col < (row); col++)
  //         {
  //           cout<<" ";
  //         }
  //       for(int i = 0; i<(n-row); i++)
  //         {
  //           cout<<"* ";
  //         }
  //       cout<<endl;
  //     }

  // for(int row = 0; row<n; row++)
  //   {
  //     for(int col = 0; col<row+1; col++)
  //       {
  //         // cout<<"* ";
  //         cout<<row + 1;
  //       }
  //     cout<<endl;
  //   }




      // hollow diamond 
  // int n;
  // cin>>n;

  // for(int row = 0; row<n; row++)
  //   {
  //     // outer spaces
  //     for(int col = 0; col<n-row-1; col++)
  //       {
  //         cout<<" ";
  //       }
  //     // innner spaces
  //     // but first stars then spaces
  //     for(int i = 0; i<2*row+1; i++)
  //       {
  //         if(i == 0 || i == 2*row)
  //         {
  //           cout<<"*";
  //         }
  //         else
  //         {
  //           cout<<" ";
  //         }
  //       }
  //     cout<<endl;
  //   }
  // for(int row =0; row<n; row++)
  //   {
  //     for(int col =0; col<row; col++)
  //       {
  //         cout<<" ";
  //       }
  //     //inner spaces and stars
  //     for(int i = 0; i<(2*n-2*row-1); i++)
  //       {
  //         if(i == 0 || i == (2*n-2*row-2))
  //         {
  //           cout<<"*";
  //         }
  //         else
  //         {
  //           cout<<" ";
  //         }
  //       }
  //     cout<<endl;
  //   }





  
 //  in rectangle a hollow diamond
  // int n;
  // cin>>n;

  // for(int row =0; row<n; row++)
  //   {
  //     for(int col = 0; col<n-row; col++)
  //       {
  //         cout<<"*";
  //       }
  //     for(int i = 0; i<2*row+1; i++)
  //       {
  //         cout<<" ";
  //       }
  //     for(int j = 0; j<n-row; j++)
  //       {
  //         cout<<"*";
  //       }
  //     cout<<endl;
  //   }
  // for(int row = 0; row<n; row++)
  //   {
  //   for(int col = 0; col<row+1; col++)
  //     {
  //       cout<<"*";
  //     }
  //   for(int i = 0; i<2*n-2*row-1; i++)
  //     {
  //       cout<<" ";
  //     }
  //   for(int j = 0; j<row+1; j++)
  //     {
  //       cout<<"*";
  //     }
  //   cout<<endl;
  //   }


  // two right angled triangle with numbers and between them stars
 //  int n;
 //  cin>>n;
 //  for(int row=0; row<n; row=row+1) {
		
	// 	for(int col=0; col<row+1; col = col + 1) {
	// 		cout << row+1;
	// 		if(col != row)
	// 			cout << "*";
	// 	}
	// 	cout << endl;
	// }

	// for(int row=0; row<n; row=row+1) {
		
	// 	for(int col=0; col<n-row; col = col + 1) {
	// 		cout << n-row;
	// 		if(col != n-row-1)
	// 			cout << "*";
	// 	}
	// 	cout << endl;
	// }



  // alphabetical order pattern instead 1 and 2 soon 

 //  int n;
	//   cin >> n;

	// for(int row=0; row<n; row=row+1) {
		
	// 	int col;
	// 	for( col=0; col<row+1; col=col+1) {
	// 		int ans = col + 1;
	// 		char ch = ans + 'A' -1;
	// 		cout << ch;
	// 	}
		
	// 	//reverse counting printing
	// 	for(int col=row; col>=1; col=col-1) {
	// 		int ans = col;
	// 		char ch = ans + 'A' -1;
	// 		cout << ch;
	// 	}
	// 	cout << endl;
	// }



  // hollow square

  // int n;
  // cin>>n;

  // for(int row = 0; row<n; row++)
  //   {
  //       if(row == 0 || row == n-1)
  //       {
  //     for(int col = 0; col< n; col++)
  //         {
  //           cout<<"*";
  //         }
  //       }
  //         else
  //         {
  //           cout<<"* ";
  //           for(int i = 0; i<n-2; i++)
  //             {
  //               cout<<" ";
  //             }
  //           cout<<"* ";
  //         }
  //         cout<<endl;
        
      
  //   }

  // hollow right triangle

  int n;
  cin>>n;

  for(int row = 0; row<n; row++)
  {
    for(int col = 0; col<2*n-2*row-1; col++)
    {
      if(row == 0)
      {
        for(int i = 0; i<n; i++)
        {
          cout<<"* ";
        }
      }
      else if(row == n-1)
      {
        cout<<"* ";
      }
     else{
    //    if(col == 0)
    //    {
    //      cout<<"* ";
    //    }
    //    else if(col == n-1)
    //    {
    //      cout<<"* ";
    //    }
    //    else{
    //      cout<<" ";
    //    }
    cout<<" ";
     }
    }
    cout<<endl;
  }
}
