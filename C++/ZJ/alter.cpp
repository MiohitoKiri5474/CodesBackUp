#include<bits/stdc++.h>

using namespace std;

struct point{
    int x;
    int y;
};

bool cmp(point a,point b){
    if(a.x==b.x)
        return a.y<b.y;
    else
        return a.x<b.x;

}

int main(){
    int n;
    cin >> n;
    point p[n];
    int l[n];
    for(int i=0;i<n;i++){
        l[i]=1;
    }
    for(int i=0;i<n;i++){
        int inx,iny;
        cin >> inx >> iny;
        p[i].x=inx;
        p[i].y=iny;
    }
	int mx = 0;
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j].y<=p[i].y)
                l[i]=max(l[i],l[j] + 1);
        }
		mx = max ( l[i], mx );
    }
    cout << mx << endl;
    return 0;
}

/*
 * A ( 2, 3 )
 * B ( 3, 3 )
 * A -> B -> C -> D
 * A -> E -> F -> G
 */

