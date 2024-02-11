#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class MedianOfStream
{
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;

    MedianOfStream(){
        maxH = priority_queue<int>();
        minH = priority_queue<int, vector<int>, greater<int>>();
    }

    void InsertNum(int num){
      maxH.push(num);

      if(!minH.empty() && !maxH.empty() && (maxH.top() > minH.top())) {
          minH.push(maxH.top());
          maxH.pop();
      }

      if(maxH.size() > minH.size() + 1) {
          minH.push(maxH.top());
          maxH.pop();
      }

      if(minH.size() > maxH.size() + 1) {
          maxH.push(minH.top());
          minH.pop();
      }
    }
    // This function should return the median of the stored numbers
    double FindMedian(){
        if(minH.size() == maxH.size())
            return (maxH.top() + minH.top())/2.0;
        if(maxH.size() > minH.size())
            return maxH.top();
        if(minH.size() > maxH.size())
            return minH.top();
        else
            return 0.0;
    }
};

int main () {
    MedianOfStream medianOfStream;
    medianOfStream.InsertNum(3);
    cout << medianOfStream.FindMedian() << endl;
    medianOfStream.InsertNum(1);
    cout << medianOfStream.FindMedian() << endl;
    medianOfStream.InsertNum(5);
    cout << medianOfStream.FindMedian() << endl;
    medianOfStream.InsertNum(4);
    cout << medianOfStream.FindMedian() << endl;
    medianOfStream.InsertNum(2);
    cout << medianOfStream.FindMedian() << endl;
    medianOfStream.InsertNum(6);
    cout << medianOfStream.FindMedian() << endl;
    return 0;
}