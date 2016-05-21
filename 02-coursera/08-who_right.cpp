// 4名专家对4款赛车进行评论
//
// 1）A说：2号赛车是最好的；
//
// 2）B说：4号赛车是最好的；
//
// 3）C说：3号赛车不是最好的；
//
// 4）D说： B说错了。
#include <iostream>
using namespace std;

int main(void)
{
	int right;
	bool a, b, c, d;

	for(right = 1; right < 5; right++)
	{
		a = (2 == right);
		b = (4 == right);
		c = !(3 == right);
		d = !b;
		if(1 == (a+b+c+d))
			break;
	}

	cout << right << endl;
	if(a) cout << "a" << endl;
	if(b) cout << "b" << endl;
	if(c) cout << "c" << endl;
	if(d) cout << "d" << endl;
	return 0;
}
