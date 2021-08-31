// compile standard: C++17
// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
#define REPALL(i,n) for ( auto &i: n )
#define debuger cout << "111\n"
#define MEM(n,i) memset ( n, i, sizeof n )
#define endl '\n'

// define pair
typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair

// define vector && some stl's api
template < class T > using vec = vector < T >;
typedef vec < int > vi;
typedef vec < LL > vl;
#define pb push_back
#define ep emplace_back
#define REV reverse
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'
#define GETDATA(data,n) RSZ ( data, n ); REPALL ( i, data ) cin >> i

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) ( n.find ( Index ) != n.end() )

// graph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 100005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

/*
                                                                                  ```....``                                                                               
                                                                       `-:/+osyyhhhhhhhhhhhhyso/:.`                                                                       
                                                                 .:/oyhhhhyyyyyyyyyyyyyyyyyyyyyyyyhyo/:.                                                                  
                                                            .:+shhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhys/-`                                                             
                                                        -/oyhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys/-                                                          
                                                    ./shhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo:`                                                      
                                                 ./shyyyyyyyyyyyyyyyyyyyyyyysso++/::--......-://+osyyyyyyyyyyyyyyyyys:`                                                   
                                              `:syyyyyyyyyyyyyyyyyyyyyso+/-.```                  ``.-:+ossyyyyyyyyyyyyyo:`                                                
                                            -os+/yyyyyyyyyyyyyyyss+/-.`                                 ``-:+osyyyyyyys/+so-                                              
                                         `:so/:-/syyyyyyyyyyso/:.`                                           ``-/+syyyyo::/os/`                                           
                                       `/so:---:syyyyyyyys+:``                `.-::::::::::::::---.`              `-/osys+:::+so-                                         
                                     `/so:---:+syyyyyso/.`             `.-:///:-.`````       ````..-:/::-.`          `.:+ssssosyhs-                                       
                                   `/yy+///+ossyyyyo/.`            .-://-.``      .o+-      `+o/`     ``.-:/:-.          `-+syyyyyhs:                                     
                                  :yhyyysssyyyyys+-`           `-:/:.`   -/.     :o:-++.   :o/.:o:`   -+o:  `.-/:-.         .:osyyyyhs:                                   
                                .ohyyyyyyyyyyys/.           .://-.     `++:++:..o/.```-+/-o/.```.:o::o/-.++`    `-:/:-        `.+syyyyhs-                                 
                               /yyyyyyyyyyyys/.          `://.``++/:` .o/.```-:/-```````-/-````````::.````:o- `-+++``-/:-`       ./syyyyho.                               
                             .shyyyyyyyyyys+.         `-//-`  .o:.-:/+o-`````.`````````````````````````````.+++:../o.  `-//-`      `:oyyyhy/                              
                            :yyyyyyyyyyyso-         .:+/+:.  :+.````````````.:.``````````````````````````````.`````-o:  ./:-/:.      `:syyyhs.                            
                          `+hyyyyyyyyyys:`        -//..o::/++/``````````````-/:```````````````````````````.`````````.+++/-o: .:/-`     `/syyyh:                           
                         `ohyyyyyyyyys/`       `-+/. :o-````.```````````.```-//-`..```````````````````````+.``````````.````+/` `-//.     .+syyh+`                         
                        .shyyyyyyyys+.       `-+o:``++``````````````````:.``-///.--```````````````````````:s````````````````/o../:.//.     -oyyhs.                        
                       .yhyyyyyyyys-        -+:/o:/+:``````````````````/+-``-///:-:```````````````````````.h/````````````````-+/-/o.`//.    `+syhy.                       
                      .yyyyyyyyys+`       -+/`/o.``````````````````````oo:``-//////-```````````````````````y+-````````.```````````-o/`.+/`    :syhh.                      
                     .yhyyyyyyys/`      `++``++````````````..``````````ys/-`-//////:```````````````````````h.o`````````-.```````````:o/++o-    .oyhh.                     
                    `yhyyyyyyys:       :o++/+/```````````./.``````````-oy/:`.///////.``````````````````````h`+-```````/`--.```````````:``.+/`   `oyhy.                    
                   `shyyyyyyys:      .o+..`..```````````-o-..`````````o.o+/-`///////:````````````-````````.h -o```````o/`./+``````````````.:o`   `oyhy`                   
                   ohyyyyyyys:      :o:.```````````````:o:-.``./.````:+`:h//.:///////-```````````s````````:y-.y```````/-+`./o```````````````-o.   `oyho                   
                  /hyyyyyyys:     `+o..```````````````-s/-.``:o+````.s::.oo/:-////////``````````-s:```````o:`-y:.`````-/.o`-+o```````````````-o-   .syd/                  
                 -dyyyyyyyy/     `o/..```````````````.s/:.`:/:+```.:s:`  `s//:////////:`````````o-+```````y`  +/-::-.`.o -o`-+o```````````````.s.   :syh.                 
                `yhyyyyyyyo     `s/.`````````````````o+:-:/..o-::::s-     .s///////////-```````-h`o``````//   /:```--:/s.`//`:o+```````````````.s.   oyhs                 
                +hyyyyyyys.    `s:.`````````````````-y/++:-/o:-.`.+.       ./+++++////++:.----:o/ o--...-+`   //------:+..`s.-/s-```````````````-o`  .syd:                
               .dyyyyyyys:    `s:.``````````````````os/.`` /////:-`          ``..---::::----..``  `......     `..-.--..`   .::+oy````````````````:+   /yhh/`              
               sdyyyyyyyo     o/.``````````:````````y`                                                                          +/````````````````+:  `sydhy-             
              :hyyyyyyys.    /o.```````````+-``````.s                                                                           .y```````:````````.y   /yhhyho.           
            .ohyyyyyyyy+    .y.````````````:+``````:o                                                                            y.`````-/`````````y-  .sydyyyh/          
           /hyyyyyyyyyy-    o/.`````````````y.`````:+                                                                            +:`````o.`````````o+   oydyyyyhs.        
         `shyyyyyyyyyyo    .y.``````````````:s`````:o`ooooooooo+++//::-.`````                              ```.--:::///++++++/-  //````.s``````````/s   /yhhyyyyyh:       
        -hhyyyyyyyyyyy/    +o-```````````````++````-s-ddddddddddddddddddddhyy/                            /yhdddddddddddhhhhhho  /+````s-``````````-y   .yydyyyyyyh+      
       :hyyyyyyyyyyyyy-    y//````````````````++```.y ```````....--::/+hdddddo                            /hdddh+-.`````         //```o:```````````.h`  `sydyyyyyyyho`    
      /dyyyyyyyyyyyyys`   .s:+`````````````````/o.``s`             `/sdddds/`               `      `        -/sdddho:`           o-``o:`````````````h`   oyhhyyyyyyyhs    
     /dyyyyyyyyyyyyyyo    :+/+``````````````````.o:`//          `/sdddho:`           `    ``      `      `     `-+ydddy/.       `y`-o-`````````-````y.   /yhhyyyyyyyyho   
    /dyyyyyyyyyyyyyyy+    //+/````````````````````++-o       `:sdddho:`                  ``      `      `          ./sdddy/.    -+/o``````````::````o/   :yhhyyyyyyyyyh+  
   :dyyyyyyyyyyyyyyyy/    +/s-````````````````````:/`-`   `-ohddds:`               .-:-.`      ``  `-::::.            `:ohddy/` :-`o``````````s`````-y   :yhdyyyyyyyyyyd- 
  -dyyyyyyyyyyyyyyyyy/    /oy``````````````````````y`   -+hddds/`               `////.-+//+:`    -+s:./:.oo`             `-ohdo   `s`````````/+``````y:  :yydyyyyyyyyyyyy`
 `yhyyyyyyyyyyyyyyyyy+    -d+``````````````````````+:  -hddy/.`                 o++/://:/+:/o/:/+++::/::/::s`         ```````.`   -o````````-s```````-y` /yhdyyyyyyyyyyyh/
 +dyyyyyyyyyyyyyyyyyyo    `h.``````````````````````.y`  -/.````````````````    -o::::::::::::::::::::::::::y-   ``````````````````s-```````-s.````````+s oyhhoyhyyyyyyyyh+
`dyyyyyyyyyyyyyyyyyyys    ++````````````````````````:s` `````````````````````` :+::::::::::::::::::::::::::y.  ``````````````````:o```````/o```````````oossdo `.:+syhyyhy.
-dyyyyyyyyyyyyyyhyyyyy.  -s``````````````````````````/o``````````````````````` `s::::::::::++/:-:/+/::::::/o   `````````````````-y.`````.o/``./:````````+hyd-      ``..`` 
 oyhhhhyyyso+/:-hyyyyy/ .y.`````````.-`````--`````````+o`````````````````````   -++/::///+/.`     `://////:`     ``````````````-s-`````/+.`````-//:``````:yh`             
  ````````      ohyyyys.s-`````````:+```````-/-````````/o.````````````````       ``-:--.``           `````                    -o.```./+-`````````.-s+:-```.+o.            
                .dyyyyys.````````:+:``````````:+:.``````-o-````````                                                         `//```:+/.`````````````h`.:so/:--//-`         
                 shyyyo.``````.:s:``````````````-//:.````.+/`                                                             `-/-.-:sh:`.````````````:s  `syd:-://++-        
                 -dys:`````.://-o.`````````````.-``-/++:-.`-/:`                                                           `.````/h:`.:````````````s/  +yho                
                 .o/.`.-:+/:.`  -+``````````````:.````+/-:///+o/-`                                                            `oy-``:.```````````.h` -syy`                
               .//:+sssyyy:      y.`````````````.:````.s`  ```````                                                           -y+.``-:````````````o+ `syh.                 
                   `yhyyyys-     :o``````````````--````sh/.                                                                .os:```-/.``.````````:y``+yh-                  
                    `shyyyys-     o:``````````.```:.```-hyy+.                                                            .+s/````-/:``-.```````.y- /yy-                   
                     `ohyyyys-    `s-`````````--``.:-```+o-oys:.                                                      `-+o:.````-/:``--````````s+`/hs.                    
                       :yyyyys:    .s-`````````:-``-/-```s: `:oso:`      ``                                  `     `-/s/-``````://-`-:`..`````oo.+y/`                     
                        .+yyyys/`   .o:`````````::.`-/-``.s:   .:oso:.``:++:`     .:`      ..       ./.    `/+/..-/+:-s``````.://:.:/.`o.````oo:so.                       
                          ./yyyyo.   `+/````````.::.`-/:.`.s:     `-+ooso-.:+-``-/:-o:   `/+++.   `:o-+/``:o/-+o:-.  /:`.-``.:///-:/-`/y```.ssos-                         
                            `syyys/`   /+.```-/```:/:.-//-..s:        `-/+ooohss/-```++.:+-  -+/.-o/..-+o/+:-.`     .o`:+/`-////://-`/s+``-yhs:`                          
                             o/-+yhs:`  .+/```s+.``-:/:://:-.o+`           `.-:/++++++oss/::::/sso/-...``          `o:/-+::///////:.//o.`+hh-                             
                             o:``.:oys:`  -+-`-o+:``.://////:-/o.                     `````  ```./+.              .so/``y////////:-+://-o//o                              
                             y-`````.:oo+:.`:/-:+:+/.`-://////:/s/`                      `..`     :y            `:s+.  +o//+o///:+s+ss++.`/o                              
                            `h``````````-/+o+//+/o--/+:.-:///os+/oo:`                  `+///++    .y            .-`   :s/+os+//oyyoyy/.```/o                              
                            :o``````````````-/+osyho--:/+/:///+soo+oo:`                `++/++/   -s-                 -s+so+o/+/:..--``````-y                              
                            s:```````````````....-:/+oooossyyysssso:-:.                  ``.``.:+/.           ```.-:+yssos+::``````````````h.                             
                           -y```````````````............--:://+++oosyo+///::::::::://++++++++oss+///::::::/+oo++++//:-.......``````````````o+                             
                           s:```````````````.......................:y```..---------..+:.```   .+` ``````````-s................`````````````-h`                            
                          /s```````````````........................:hs/.`             :/.````.o`            `y................``````````````o/                            
                         .y.````..````````...............:........ohyyyyso/-``       `//y++++y:/`      `.:+oyy/....--..........`````````````.h.                           
                        `s/````:s`````````.............../......-yyyyyyyyyyyyso+:.``  ..-+++o/..  `.:+oyyyyyyyho..../..........``````````-```:y`                          
                        o+````+oo````````../............+-.....:yyyyyyyyyyyyyyyhooss+::o--s+o`:/:oys+oyyyyyyyyyys-..::..........`````````:+```+o                          
                       +o```-o-+/```````../o...........:+.....:hyyyyyyyyyyyyyyyy::yyyyyyo::h-:oyyyyy::yyyyyyyyyyyy-..o...........-````````os.``o+                         
                      +o``.++` y.``````..:h-...........s-....:hyyyyyyyyyyyyyyyh+:+hyyyyyyyyhydhhyyyh+:/hyyyyyyyyyyy-.//..........+-````````yo/``o+                        
                    `s/`.+o.  :o``````..-ho...........+/....-hyyyyyyyyyyyyyyyyy::yyyyyyhhhhdhhhyyyyyy::syyyyyyyyyyyy..+-..........o-```````-s:o-`++                       
                   -s--++.    y-`````..-ys-........../o.....yyyyyyyyyyyyyyyyyyo::hyyyyyydhhyyyyyyyyyh/:/hyyyyyyyyyyhs.:/-.........-y:```````/+`/o./s`                     
                 .oo++/`     :o`````..-y:o..........:+:....+hyyyyyyyyhyyyyyyyh/:+hyyyyyyyyyyyyyyyyyyho::yyyyhyyyyyyyh+.//..........:h/```````+/ `+o/s:                    
               .oh+/.       `y.```...:y.s-.........-/+....-hyyyyyyyyyhyyyyyyyh::ohyyyyyyyyyyyyyyyyyyyy::oyyyhyyyyyyyyh-.//..........+y+```````o:  `/+so.                  
             `--`           s:```.../s`//.........-/+.....syyyyyyyyyyhyyyyyyyy::syyyyyyyyyyyyyyyyyyyyh/:/hyyyhyyyyyyyyy.:-/..........+oo-``````o/    `:+/`                
*/

struct node {
	string name, parent, leftSon, rightSon;
	double w, h, x, y; 

	inline void print ( void ) {
		cout << name << endl;
		cout << parent << ' ' << leftSon << ' ' << rightSon << endl;
		cout << w << ' ' << h << endl;
		cout << "---\n";
	}

	inline void printPos ( void ) {
		cout << name << ": ";
		cout << x << ' ' << y << endl;
	}
};

struct queueNode {
	string name;
	double x, y;
};

map < string, node > lib;
set < string > nameList;

inline bool check ( string str ) {
	return nameList.find ( str ) != nameList.end();
}

void dfs ( string name, double x, double y ) {
	if ( !check ( name ) )
		return;
	for ( auto [f, s]: lib ) {
		if ( s.x == -1 || s.y == -1 || f == name )
			continue;
		if ( ( x < s.x && s.x < x + lib[name].w ) || ( x < s.x + s.w && s.x + s.w < x + lib[name].w ) ) {
			if ( y + lib[name].h < s.y )
				continue;
			y = max ( y, s.y + s.h );
		}

		if ( ( y < s.y && s.y < y + lib[name].h ) || ( y < s.y + s.h && s.y + s.h < y + lib[name].h ) ) {
			if ( x + lib[name].w < s.x )
				continue;
			x = max ( x, s.x + s.w );
		}
	}
	lib[name].x = x, lib[name].y = y;
	dfs ( lib[name].leftSon, x + lib[name].w, y );
	dfs ( lib[name].rightSon, x, y + lib[name].h );
}

int main ( int argc, char *argv[] ) {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	ifstream input;
	ofstream output;
	string str, nets, nodes, name = "", swp, report = "report_", matlab, nm, l, r, p, root;
	int n;
	double sum = 0, maX, maY, miX, miY, w, h, x, y;
	vector < string > in;

	// get file name
	for ( int i = 0 ; i < strlen ( argv[1] ) ; i++ )
		swp += argv[1][i];
	report = report + swp + ".txt";
	name += swp;
	nodes = name + ".nodes";
	nets = name + ".nets";
	matlab = name + ".m";

	// get b* tree data (from .nodes)
	input.open ( nodes );
	lib["X"] = node { "X", "X", "X", "X", 0, 0, -1, -1 };
	input >> swp >> swp >> n;
	while ( n-- ) {
		input >> swp >> swp >> nm;
		input >> swp >> swp >> w >> h;
		input >> swp >> swp >> p >> l >> r;
		lib[nm] = node { nm, p, l, r, w, h, -1, -1 };

		if ( p == "X" )
			root = nm;
		nameList.insert ( nm );
	}
	input.close();

	// build b* tree
	// dfs
	// dfs ( root, 0, 0 );

	// bfs
	queue < queueNode > q;
	q.push ( queueNode { root, 0, 0 } );
	while ( !q.empty() ) {
		name = q.front().name;
		x = q.front().x;
		y = q.front().y;
		q.pop();

		if ( !check ( name ) )
			continue;

		for ( auto [f, s]: lib ) {
			if ( s.x == -1 || s.y == -1 || f == name )
				continue;
			if ( ( x < s.x && s.x < x + lib[name].w ) || ( x < s.x + s.w && s.x + s.w < x + lib[name].w ) ) {
				if ( y + lib[name].h < s.y )
					continue;
				y = max ( y, s.y + s.h );
			}
	
			if ( ( y < s.y && s.y < y + lib[name].h ) || ( y < s.y + s.h && s.y + s.h < y + lib[name].h ) ) {
				if ( x + lib[name].w < s.x )
					continue;
				x = max ( x, s.x + s.w );
			}
		}
		lib[name].x = x, lib[name].y = y;
		q.push ( queueNode { lib[name].leftSon, x + lib[name].w, y } );
		q.push ( queueNode { lib[name].rightSon, x, y + lib[name].h } );
	}

	// calculate wirelength (form .nets);
	input.open ( nets );
	input >> swp >> swp >> n >> swp;
	while ( n-- ) {
		in.clear();
		while ( input >> swp ) {
			if ( swp[0] == 'N' && swp[1] == 'E' && swp[2] == 'T' )
				break;
			in.pb ( swp );
		}
		if ( in.empty() ) {
			continue;
		}
		maX = maY = -1.0;
		miX = miY = INF * 1.0;
		for ( auto i: in ) {
			maX = max ( maX, ( lib[i].x * 1.0 + lib[i].w / 2.0 ) );
			maY = max ( maY, ( lib[i].y * 1.0 + lib[i].h / 2.0 ) );
			miX = min ( miX, ( lib[i].x * 1.0 + lib[i].w / 2.0 ) );
			miY = min ( miY, ( lib[i].y * 1.0 + lib[i].h / 2.0 ) );
		}

		sum += ( maX - miX ) + ( maY - miY );
	}
	input.close();

	w = 0, h = 0;
	for ( auto [f, s]: lib ) {
		if ( !check ( f ) )
			continue;
		w = max ( w, s.x + s.w );
		h = max ( h, s.y + s.h );
	}

	// report
	output.open ( report );
	output << "Benchmark : " << name << '\n';
	output << "Wirelength : " << sum << endl;
	output << "Area : " << LL ( w ) * LL ( h ) << '\n';
	output.close();

	// matlab
	output.open ( matlab );
	output << "axis equal;\nhold on\ngrid on\n\n% area range\n";
	output << "block_x = [ 0 0 " << w << ' ' << w << " 0 ];\n";
	output << "block_y = [ 0 " << h << ' ' << h << " 0 0 ];\n";
	output << "fill ( block_x, block_y, \'w\', \'Edgecolor\', \'r\' );\n";
	for ( auto [f, s]: lib ) {
		if ( !check ( f ) )
			continue;
		output << "\n% " << f << endl;
		output << "block_x = [ " << s.x << ' ' << s.x << ' ' << s.x + s.w << ' ' << s.x + s.w << ' ' << s.x << " ];\n";
		output << "block_y = [ " << s.y << ' ' << s.y + s.h << ' ' << s.y + s.h << ' ' << s.y << ' ' << s.y << " ];\n";
		output << "fill ( block_x, block_y, \'c\' );\n";
		output << "text ( " << s.x + s.w / 2.0 << ", " << s.y + s.h / 2.0 << ", \'" << f << "\' );\n";
	}
	output.close();
}
