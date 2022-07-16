#include <iostream>

#include <vector>

using namespace std;

int valueOfgreaterthansum(vector<int> &v)

{   

    int sum=0;

    for(int i=0; i<v.size(); i++){

       sum+=v[i];

    }

    //further sum is divided no of interger have

    float no=float(sum)/v.size();

    

    int max = 0, min = 0;

    for (int i = 0; i < v.size(); i++)

    {

        if (no <v[i])

        {

            max++;

        }

        else

        {

            min++;

        }

    }

    cout<<"total no in element is           :"<<v.size()<<endl;

    cout<<"sum of no is                     :"<<sum<<endl;

    cout<<"after divided                    :"<<no<<endl;

    cout <<"no of element is greter than sum :" << max << endl;

    cout <<"no of element is lesser than sum :" << min << endl;

    return max;

}

pair<int, int> maxdifferenceBetweenelement(int no)

{

    // puting interger element in vector

    int a = 0, b = 0;

    vector<int> v;

    while (no > 0)

    {

        a = no % 10;

        v.push_back(a);

        b = no / 10;

        no = b;

    }

    

    int max = v[0], min = v[0];

    for (int i = 0; i < v.size(); i++)

    {

        if (max < v[i])

        {

            max = v[i];

        }

        if (min > v[i])

        {

            min = v[i];

        }

    }

    //

    pair<int, int> pair3;

    pair3.first = max - min;

    cout << " max -->" << max << endl;

    cout << " min -->" << min << endl;

    cout<<"maxdifferenceBetweenelement is   :"<<pair3.first<<endl;

    // i am calling another function for 28june problem

    pair3.second = valueOfgreaterthansum(v);

    return pair3;

}

int main()

{

    int number;

    cout << "Enter your number :" << endl;

    cin >> number;

    auto k = maxdifferenceBetweenelement(number);

   // cout<<"maxdifferenceBetweenelement is "<<k.first<<endl;

}
