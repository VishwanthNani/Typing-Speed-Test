#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>

int x=1;//used for x cursor co-ordinate
#define pos gotoxy(33,x++) /*for cursor movement*/
#define ln  printf(".......................");
//.......................................................................................................................................................................
 COORD coord={0,0};
 void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//.......................................................................................................................................................................
void delay(unsigned int mseconds)//function for delay
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}
//.............................................................................................................................................................................
struct letters{
    int X;
    int Y;
    char a;
    int color;
    int bgcolor;
    char a2;
};

void setbgcolor(int n)
{
    switch(n)
    {
        case 10:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);break;
        case 11:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY);break;
        case 12:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY);break;
        case 14:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);break;
        case 13:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);break;
        case 0: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);break;
	}
}
//..........................................................................................................................................

void setcolor(int ForgC) //function to change setcolor
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }

//.................................................................................................................................................................................
void sett();//sets time limit for playing game
int t=30;
int c=0;

char name[15];
void getscore(int score,int speed,int level);
void startgame();  //to start the game
void scorecard();  //to update high score
void About_me();
void help();
void beginner();
void easy();
void normal();
void hard();
void print_score(int,int,int,int,int);
void arectangle(int x,int y, int l,int b,int color,char str[15]);
void keyboard(int x,int y);
void leter(struct letters);
//...............................................................................................................................................................................
//			main function
int main()
{       char ch;
		int i;

	time_t t;
	time(&t);	
	x=1;
	system("cls");

	pos;
	pos;setcolor(11);
	if(c==0)
	printf("ENTER TO FULL SCREEN MODE FOR BETTER EXPERIENCE");
	delay(2000);
	system("cls");
	keyboard(15,20);
	x=1;
	pos;
	setcolor(10) ;
	printf("  TYPING SPEED TEST ");
	setcolor(11) ;
	pos;
	printf("%s",ctime(&t));//printing time
	pos;
    ln 
	pos;
	if(c==0)
	   {	
		printf("Enter player's name::");
		gets(name);
	   }

	else
	   printf("Enter player's name::%s",name);
       if(name[0]!='\0')
       c++;
       if(name[0]=='\0'){
        pos;
        setcolor(12);
        pos;pos;
       printf("*Name should be entered!");
       delay(1500);
       system("cls");
       main();
       }
	    pos;
		ln
		pos;
		setcolor(14);
		printf("#..MAIN MENU..#");pos;
		ln
		pos;
		printf("1.startgame");
		pos;
		printf("2.scorecard");
		pos;
		printf("3.Set the time limit::");
		pos;
		printf("4.Help");
		pos;
		printf("5.About me");
		pos;
		printf("0.exit");
		pos;
		printf("Enter your choice::");
		ch=getche();

		switch(ch)
	   {      
		    case '1':startgame();break;
			case '2':scorecard();break;
			case '3':sett();main();
			case '4':help();break;
			case '5':About_me();break;
			case '0':system("cls");
	    			gotoxy(35,25);
			         printf("#This Game is created by IIT BBS STUDENTS#");
			         delay(1000);
					 exit(1);
			default :pos;pos;setcolor(12);printf("....invalid input....");
					delay(1000);
					main();
	   }
	   
}

//.....................end of main function.................................

			   //startgame
//..........................................................................
void startgame()
{      

    char level;
	clock_t begin;int time_spent,speed;
	char ch;
	delay(500);
	system("cls");
	x=2;
	pos;
	setcolor(10);
	printf("#select the Mode#");pos;
	ln
	pos;
	setcolor(13);
	printf("1.Beginner mode");
	pos;
	printf("2.Easy mode");
	pos;
	printf("3.Normal mode");
	pos;
	printf("4.Hard mode");
	pos;
	printf("5.Back to main menu#");
	pos;
	level=getche();
	system("cls");
	switch(level){
		case '1':beginner();break;
		case '2':easy();break;
		case '3':normal();break;
		case '4':hard();break;
		case '5':main();
		default:pos;pos;setcolor(12); printf("....Invalid input....");delay(1000);startgame();
		
	}
		++x;
		pos;
		setcolor(9);
		printf("1.# play again #");
		pos;

		printf("2.# main menu #");pos;
		printf("3.exit");
		pos;
		setcolor(2);
		printf("Enter your choice::");
		ch=getche();
		switch(ch)
		{
		      case '1':startgame();break;//recursive call
		      case '2':main();break;
		      case '3':system("cls");gotoxy(17,10);printf("#This Game is created by IIT BHUBANESWAR students #");delay(1000);exit(1);
		      default:pos;setcolor(12);printf("....Invalid input ....") ;pos;printf("....Returning to main menu.....");delay(1000);
				main();
		}

	

}
//......................end of start game function..........................


//...........................sett function starts..........................
void sett()  //set time limit
{
	char ch;
	system("cls");
	//rectangle(0,0,70,15);
	setcolor(13);
	x=5;
	pos;
	printf("Set the time limit for game in minute::");
	pos;
	ln
	pos;
	setcolor(9);
	printf("press 0 for half minute") ;pos;
	printf("press 1 for 1 minute"); pos;
	printf("press 2 for 2 minutes");pos;
	printf("press 3 for 5 minutes");pos;
	printf("press 4 for Main menu");pos;
	ch=getche();
	switch(ch)
	{
		case '0':t=30;break;
		case '1':t=60;break;
		case '2':t=120;break;
		case '3':t=300;break;
		case '4':main();
		default:pos;pos;printf("....Invalid input....");delay(1500);sett();
	}
}
//....................sett function ends....................................

//........................................................................
void help()
{
system("cls");
	x=3;
	pos;
	setcolor(6);

	printf("#......Rules of the Game......#");pos;pos;
	printf("Enter your name as player name");pos;
	printf("Set the time limit under option 3 in main menu(default limit is 30 sec)");pos;
	printf("select the level and get started :");pos;
	printf("Characters are displayed and you have to type them as fast as you can..");pos;
	printf("The keyboard below makes it easier for users to select the right finger for a desired character.");pos;
	arectangle(10,x+1,20,3,11,"    Little finger");
	arectangle(32,x+1,20,3,12,"    Ring finger");
	arectangle(54,x+1,20,3,14,"    Middle finger");
	arectangle(76,x+1,20,3,10,"    Index finger");
	arectangle(98,x+1,20,3,13,"   Thumb finger");
    keyboard(10,20);
    setcolor(6);
	gotoxy(55,41);
	printf("THANK YOU !");

	getch();main();
}
void About_me()
{       system("cls");x=8;
	gotoxy(33,7);
	setcolor(11);
	printf("This project is made by Btech 1st year students of IIT Bhubhaneswar");
	pos;pos;
	setcolor(13);
	printf("CONTRIBUTERS::");
	pos;setcolor(14);
	printf("M Ravindra Reddy");
	pos;
	printf("D Vishwanth Reddy");
	pos;
	printf("N Hari Naik");
	pos;
	printf("A Sethu Raman");pos;
	printf("G Phanindra Kumar");
   
       getch();
       main();
}
//.........................................................................
void getscore(int score,int speed,int level)
{
	FILE *fp;
	fp=fopen("file.txt","a");
	pos;
	if(fp==NULL)
	printf("error in opening file");
	fprintf(fp,"\nname=%s   score=%d    speed=%d    level=%d",name,score,speed,level);
	fclose(fp);
	pos;
	printf("scorecard updated");
	
}
//...........................................................................
void scorecard()
{       int ch;
	FILE *fp;
	system("cls");
	//rectangle(0,0,70,15);
	x=3;

	printf("\t\t\t....The scores are...\n");

	fp=fopen("file.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{	printf("%c",ch);
	}
	getch();
	main();
}
//.........................................................................................................................................
void print_score(int speed,int score,int level,int mistakes,int words)
{
 	setcolor(13);
	system("cls");
		pos;
			printf("Times up !Game over!");
			pos;pos;
			setcolor(11);
			if((speed>=20)&&(speed<=30))
			{	
				printf("Congragulations %s",name);
				pos;
				printf("Good Work !Keep it up!");pos;

				printf("You got silver medal");
			}
			else if(speed>30)
			{
				printf("Congragulations %s",name);pos;
				printf("Nice work! You got Gold medal");pos;
			}
			else
			printf("Sorry no medal !you need practise..");
		pos;
		setcolor(14);
		printf("Total score is ::%d",score);
		if(level!=1)
		{
			pos;
        	printf("Number of words:: %d",words);
		}
		else
		{
			pos;
			printf("Number of characters:: %d",words);
		}
		pos;
		printf("Number of mistakes:: %d",mistakes);
		pos;
		if(level!=1)
		printf("Your net speed=%d words per minute",speed);
		else
		printf("Your net speed=%d characters per minute",speed);

		getscore(score,speed,level);//saves data to file
}
//.................................................................................................................................................
void beginner()
{
    int level=1;
    int k=0;
    int r,score=0,words=0,mistakes=0;
    srand(time(0));
    
    clock_t begin=clock() ;
	x=2;
	pos;
	setcolor(12);
	printf("Enter the following characters");
	pos;
    keyboard(10,15);
    while(((int)(clock()-begin)/CLOCKS_PER_SEC)<t)
    {
    
		
		x=3;

        r=rand()%123;
        while(!((r>49&&r<58)||(r>64&&r<91)||(r>96&&r<123)))
        {
            r=rand();
        }
		pos;
        printf("%c",r);
		pos;
        char ch;
            setcolor(10);
        printf(" \b");
            
        while (1) 
       {
            if (_kbhit())
            {
                ch=getche();

            
             break;
            }

            int currentTime = time(NULL);
             if (((int)(clock()-begin)/CLOCKS_PER_SEC)>=t) 
            {
              k=1;  
              break;
            }
        }

        if(k==1)
        break; 
            while(ch!=r)
            {
                printf("\b \b");
				mistakes++;
                while (1) 
	    	   {
					if (_kbhit())
					{
						ch=getche();

				
					break;
					}

					int currentTime = time(NULL);
					if (((int)(clock()-begin)/CLOCKS_PER_SEC)>=t) 
					{
					k=1;  
					break;
					}
        		}

				if(k==1)
				break; 
                
            }


     setcolor(15);


        score=score+10;
        words++;
        printf("\n");
    }


int speed=words*60/t;
print_score(speed,score,level,mistakes,words);
}
//..................................................................................................................................
void easy()
{
	 int level=2;
    int k=0;
    int r,score=0,words=0,mistakes=0;
    char word[2466][20]={ "aback","abaft","abandoned","abashed","aberrant", "abhorrent", "abiding", "abject", "ablaze", "able", "abnormal","aboard","aboriginal","abortive", "abounding", "abrasive", "abrupt", "absent", "absorbed", "absorbing", "abstracted", "absurd", "abundant", "abusive", "accept", "acceptable", "accessible", "accidental", "account", "accurate", "achiever", "acid", "acidic", "acoustic", "acoustics", "acrid", "act", "action", "activity", "actor", "actually", "ad hoc", "adamant", "adaptable", "add", "addicted", "addition", "adhesive", "adjoining", "adjustment", "admire", "admit", "adorable", "adventurous", "advertisement", "advice", "advise", "afford", "afraid", "aftermath", "afternoon", "afterthought", "aggressive", "agonizing", "agree", "agreeable", "agreement", "ahead", "air", "airplane", "airport", "ajar", "alarm", "alcoholic", "alert", "alike", "alive", "alleged", "allow", "alluring", "aloof", "amazing", "ambiguous", "ambitious", "amount", "amuck", "amuse", "amused", "amusement", "amusing", "analyze", "ancient", "anger", "angle", "angry", "animal", "animated", "announce", "annoy", "annoyed", "annoying", "answer", "ants", "anxious", "apathetic", "apologise", "apparatus", "apparel", "appear", "applaud", "appliance", "appreciate", "approval", "approve", "aquatic", "arch", "argue", "argument", "arithmetic", "arm", "army", "aromatic", "arrange", "arrest", "arrive", "arrogant", "art", "ashamed", "ask", "aspiring", "assorted", "astonishing", "attach", "attack", "attempt", "attend", "attract", "attraction", "attractive", "aunt", "auspicious", "authority", "automatic", "available", "average", "avoid", "awake", "aware", "awesome", "awful", "axiomatic", "babies", "baby", "back", "bad", "badge", "bag", "bait", "bake", "balance", "ball", "ban", "bang", "barbarous", "bare", "base", "baseball", "bashful", "basin", "basket", "basketball", "bat", "bath", "bathe", "battle", "bawdy", "bead", "beam", "bear", "beautiful", "bed", "bedroom", "beds", "bee", "beef", "befitting", "beg", "beginner", "behave", "behavior", "belief", "believe", "bell", "belligerent", "bells", "belong", "beneficial", "bent", "berry", "berserk", "best", "better", "bewildered", "big", "bike", "bikes", "billowy", "bird", "birds", "birth", "birthday", "bit", "bite", "bite-sized", "bitter", "bizarre", "black", "black-and-white", "blade", "bleach", "bless", "blind", "blink", "blood", "bloody", "blot", "blow", "blue", "blue-eyed", "blush", "blushing", "board", "boast", "boat", "boil", "boiling", "bolt", "bomb", "bone", "book", "books", "boorish", "boot", "border", "bore", "bored", "boring", "borrow", "bottle", "bounce", "bouncy", "boundary", "boundless", "bow", "box", "boy", "brainy", "brake", "branch", "brash", "brass", "brave", "brawny", "breakable", "breath", "breathe", "breezy", "brick", "bridge", "brief", "bright", "broad", "broken", "brother", "brown", "bruise", "brush", "bubble", "bucket", "building", "bulb", "bump", "bumpy", "burly", "burn", "burst", "bury", "bushes", "business", "bustling", "busy", "butter", "button", "buzz", "cabbage", "cable", "cactus", "cagey", "cake", "cakes", "calculate", "calculating", "calculator", "calendar", "call", "callous", "calm", "camera", "camp", "can", "cannon", "canvas", "cap", "capable", "capricious", "caption", "car", "card", "care", "careful", "careless", "caring", "carpenter", "carriage", "carry", "cars", "cart", "carve", "cast", "cat", "cats", "cattle", "cause", "cautious", "cave", "ceaseless", "celery", "cellar", "cemetery", "cent", "certain", "chalk", "challenge", "chance", "change", "changeable", "channel", "charge", "charming", "chase", "cheap", "cheat", "check", "cheer", "cheerful", "cheese", "chemical", "cherries", "cherry", "chess", "chew", "chicken", "chickens", "chief", "childlike", "children", "chilly", "chin", "chivalrous", "choke", "chop", "chubby", "chunky", "church", "circle", "claim", "clam", "clammy", "clap", "class", "classy", "clean", "clear", "clever", "clip", "cloistered", "close", "closed", "cloth", "cloudy", "clover", "club", "clumsy", "cluttered", "coach", "coal", "coast", "coat", "cobweb", "coherent", "coil", "cold", "collar", "collect", "color", "colorful", "colossal", "colour", "comb", "combative", "comfortable", "command", "committee", "common", "communicate", "company", "compare", "comparison", "compete", "competition", "complain", "complete", "complex", "concentrate", "concern", "concerned", "condemned", "condition", "confess", "confuse", "confused", "connect", "connection", "conscious", "consider", "consist", "contain", "continue", "control", "cooing", "cook", "cool", "cooperative", "coordinated", "copper", "copy", "corn", "correct", "cough", "count", "country", "courageous", "cover", "cow", "cowardly", "cows", "crabby", "crack", "cracker", "crash", "crate", "craven", "crawl", "crayon", "crazy", "cream", "creator", "creature", "credit", "creepy", "crib", "crime", "crook", "crooked", "cross", "crow", "crowd", "crowded", "crown", "cruel", "crush", "cry", "cub", "cuddly", "cultured", "cumbersome", "cup", "cure", "curious", "curl", "curly", "current", "curtain", "curve", "curved", "curvy", "cushion", "cut", "cute", "cycle", "cynical", "dad", "daffy", "daily", "dam", "damage", "damaged", "damaging", "damp", "dance", "dangerous", "dapper", "dare", "dark", "dashing", "daughter", "day", "dazzling", "dead", "deadpan", "deafening", "dear", "death", "debonair", "debt", "decay", "deceive", "decide", "decision", "decisive", "decorate", "decorous", "deep", "deeply", "deer", "defeated", "defective", "defiant", "degree", "delay", "delicate", "delicious", "delight", "delightful", "delirious", "deliver", "demonic", "depend", "dependent", "depressed", "deranged", "describe", "descriptive", "desert", "deserted", "deserve", "design", "desire", "desk", "destroy", "destruction", "detail", "detailed", "detect", "determined", "develop", "development", "devilish", "didactic", "different", "difficult", "digestion", "diligent", "dime", "dinner", "dinosaurs", "direction", "direful", "dirt", "dirty", "disagree", "disagreeable", "disappear", "disapprove", "disarm", "disastrous", "discover", "discovery", "discreet", "discussion", "disgusted", "disgusting", "disillusioned", "dislike", "dispensable", "distance", "distinct", "distribution", "disturbed", "divergent", "divide", "division", "dizzy", "dock", "doctor", "dog", "dogs", "doll", "dolls", "domineering", "donkey", "door", "double", "doubt", "doubtful", "downtown", "drab", "draconian", "drag", "drain", "dramatic", "drawer", "dream", "dreary", "dress", "drink", "drip", "driving", "drop", "drown", "drum", "drunk", "dry", "duck", "ducks", "dull", "dust", "dusty", "dynamic", "dysfunctional", "eager", "ear", "early", "earn", "earsplitting", "earth", "earthquake", "earthy", "easy", "eatable", "economic", "edge", "educate", "educated", "education", "effect", "efficacious", "efficient", "egg", "eggnog", "eggs", "eight", "elastic", "elated", "elbow", "elderly", "electric", "elegant", "elfin", "elite", "embarrass", "embarrassed", "eminent", "employ", "empty", "enchanted", "enchanting", "encourage", "encouraging", "end", "endurable", "energetic", "engine", "enjoy", "enormous", "enter", "entertain", "entertaining", "enthusiastic", "envious", "equable", "equal", "erect", "erratic", "error", "escape", "ethereal", "evanescent", "evasive", "even", "event", "examine", "example", "excellent", "exchange", "excite", "excited", "exciting", "exclusive", "excuse", "exercise", "exist", "existence", "exotic", "expand", "expansion", "expect", "expensive", "experience", "expert", "explain", "explode", "extend", "extra-large", "extra-small", "exuberant", "exultant", "eye", "eyes", "fabulous", "face", "fact", "fade", "faded", "fail", "faint", "fair", "fairies", "faithful", "fall", "fallacious", "false", "familiar", "famous", "fanatical", "fancy", "fang", "fantastic", "far", "far-flung", "farm", "fascinated", "fast", "fasten", "fat", "faulty", "fax", "fear", "fearful", "fearless", "feeble", "feeling", "feigned", "female", "fence", "fertile", "festive", "fetch", "few", "field", "fierce", "file", "fill", "film", "filthy", "fine", "finger", "finicky", "fire", "fireman", "first", "fish", "fit", "five", "fix", "fixed", "flag", "flagrant", "flaky", "flame", "flap", "flash", "flashy", "flat", "flavor", "flawless", "flesh", "flight", "flimsy", "flippant", "float", "flock", "flood", "floor", "flow", "flower", "flowers", "flowery", "fluffy", "fluttering", "fly", "foamy", "fog", "fold", "follow", "food", "fool", "foolish", "foot", "force", "foregoing", "forgetful", "fork", "form", "fortunate", "found", "four", "fowl", "fragile", "frail", "frame", "frantic", "free", "freezing", "frequent", "fresh", "fretful", "friction", "friend", "friendly", "friends", "frighten", "frightened", "frightening", "frog", "frogs", "front", "fruit", "fry", "fuel", "full", "fumbling", "functional", "funny", "furniture", "furry", "furtive", "future", "futuristic", "fuzzy", "gabby", "gainful", "gamy", "gaping", "garrulous", "gate", "gather", "gaudy", "gaze", "geese", "general", "gentle", "ghost", "giant", "giants", "giddy", "gifted", "gigantic", "giraffe", "girl", "girls", "glamorous", "glass", "gleaming", "glib", "glistening", "glorious", "glossy", "glove", "glow", "glue", "godly", "gold", "good", "goofy", "gorgeous", "government", "governor", "grab", "graceful", "grade", "grain", "grandfather", "grandiose", "grandmother", "grape", "grass", "grate", "grateful", "gratis", "gray", "grease", "greasy", "great",
     "greedy", "green", "greet", "grey", "grieving", "grin", "grip", "groan", "groovy", "grotesque", "grouchy", "ground", "group", "growth", "grubby", "gruesome", "grumpy", "guarantee", "guard", "guarded", "guess", "guide", "guiltless", "guitar", "gullible", "gun", "gusty", "guttural", "habitual", "hair", "haircut", "half", "hall", "hallowed", "halting", "hammer", "hand", "handle", "hands", "handsome", "handsomely", "handy", "hang", "hanging", "hapless", "happen", "happy", "harass", "harbor", "hard", "hard-to-find", "harm", "harmonious", "harmony", "harsh", "hat", "hate", "hateful", "haunt", "head", "heady", "heal", "health", "healthy", "heap", "heartbreaking", "heat", "heavenly", "heavy", "hellish", "help", "helpful", "helpless", "hesitant", "hideous", "high", "high-pitched", "highfalutin", "hilarious", "hill", "hissing", "historical", "history", "hobbies", "hole", "holiday", "holistic", "hollow", "home", "homeless", "homely", "honey", "honorable", "hook", "hop", "hope", "horn", "horrible", "horse", "horses", "hose", "hospitable", "hospital", "hot", "hour", "house", "houses", "hover", "hug", "huge", "hulking", "hum", "humdrum", "humor", "humorous", "hungry", "hunt", "hurried", "hurry", "hurt", "hushed", "husky", "hydrant", "hypnotic", "hysterical", "ice", "icicle", "icky", "icy", "idea", "identify", "idiotic", "ignorant", "ignore", "ill", "ill-fated", "ill-informed", "illegal", "illustrious", "imaginary", "imagine", "immense", "imminent", "impartial", "imperfect", "impolite", "important", "imported", "impossible", "impress", "improve", "impulse", "incandescent", "include", "income", "incompetent", "inconclusive", "increase", "incredible", "industrious", "industry", "inexpensive", "infamous", "influence", "inform", "inject", "injure", "ink", "innate", "innocent", "inquisitive", "insect", "insidious", "instinctive", "instruct", "instrument", "insurance", "intelligent", "intend", "interest", "interesting", "interfere", "internal", "interrupt", "introduce", "invent", "invention", "invincible", "invite", "irate", "iron", "irritate", "irritating", "island", "itch", "itchy", "jaded", "jagged", "jail", "jam", "jar", "jazzy", "jealous", "jeans", "jelly", "jellyfish", "jewel", "jittery", "jobless", "jog", "join", "joke", "jolly", "joyous", "judge", "judicious", "juggle", "juice", "juicy", "jumbled", "jump", "jumpy", "juvenile", "kaput", "keen", "kettle", "key", "kick", "kill", "kind", "kindhearted", "kindly", "kiss", "kittens", "kitty", "knee", "kneel", "knife", "knit", "knock", "knot", "knotty", "knowing", "knowledge", "knowledgeable", "known", "label", "labored", "laborer", "lace", "lackadaisical", "lacking", "ladybug", "lake", "lame", "lamentable", "lamp", "land", "language", "languid", "large", "last", "late", "laugh", "laughable", "launch", "lavish", "lazy", "lean", "learn", "learned", "leather", "left", "leg", "legal", "legs", "lethal", "letter", "letters", "lettuce", "level", "lewd", "library", "license", "lick", "lie", "light", "lighten", "like", "likeable", "limit", "limping", "line", "linen", "lip", "liquid", "list", "listen", "literate", "little", "live", "lively", "living", "load", "loaf", "lock", "locket", "lonely", "long", "long-term", "longing", "look", "loose", "lopsided", "loss", "loud", "loutish", "love", "lovely", "loving", "low", "lowly", "lucky", "ludicrous", "lumber", "lumpy", "lunch", "lunchroom", "lush", "luxuriant", "lying", "lyrical", "macabre", "machine", "macho", "maddening", "madly", "magenta", "magic", "magical", "magnificent", "maid", "mailbox", "majestic", "makeshift", "male", "malicious", "mammoth", "man", "manage", "maniacal", "many", "marble", "march", "mark", "marked", "market", "married", "marry", "marvelous", "mask", "mass", "massive", "match", "mate", "material", "materialistic", "matter", "mature", "meal", "mean", "measly", "measure", "meat", "meaty", "meddle", "medical", "meek", "meeting", "mellow", "melodic", "melt", "melted", "memorize", "memory", "men", "mend", "merciful", "mere", "mess up", "messy", "metal", "mice", "middle", "mighty", "military", "milk", "milky", "mind", "mindless", "mine", "miniature", "minister", "minor", "mint", "minute", "miscreant", "miss", "mist", "misty", "mitten", "mix", "mixed", "moan", "moaning", "modern", "moldy", "mom", "momentous", "money", "monkey", "month", "moon", "moor", "morning", "mother", "motion", "motionless", "mountain", "mountainous", "mourn", "mouth", "move", "muddle", "muddled", "mug", "multiply", "mundane", "murder", "murky", "muscle", "mushy", "mute", "mysterious", "nail", "naive", "name", "nappy", "narrow", "nasty", "nation", "natural", "naughty", "nauseating", "near", "neat", "nebulous", "necessary", "neck", "need", "needle", "needless", "needy", "neighborly", "nerve", "nervous", "nest", "new", "next", "nice", "nifty", "night", "nimble", "nine", "nippy", "nod", "noise", "noiseless", "noisy", "nonchalant", "nondescript", "nonstop", "normal", "north", "nose", "nostalgic", "nosy", "note", "notebook", "notice", "noxious", "null", "number", "numberless", "numerous", "nut", "nutritious", "nutty", "oafish", "oatmeal", "obedient", "obeisant", "obese", "obey", "object", "obnoxious", "obscene", "obsequious", "observant", "observation", "observe", "obsolete", "obtain", "obtainable", "occur", "ocean", "oceanic", "odd", "offbeat", "offend", "offer", "office", "oil", "old", "old-fashioned", "omniscient", "one", "onerous", "open", "opposite", "optimal", "orange", "oranges", "order", "ordinary", "organic", "ossified", "outgoing", "outrageous", "outstanding", "oval", "oven", "overconfident", "overflow", "overjoyed", "overrated", "overt", "overwrought", "owe", "own", "pack", "paddle", "page", "pail", "painful", "painstaking", "paint", "pale", "paltry", "pan", "pancake", "panicky", "panoramic", "paper", "parallel", "parcel", "parched", "park", "parsimonious", "part", "partner", "party", "pass", "passenger", "past", "paste", "pastoral", "pat", "pathetic", "pause", "payment", "peace", "peaceful", "pear", "peck", "pedal", "peel", "peep", "pen", "pencil", "penitent", "perfect", "perform", "periodic", "permissible", "permit", "perpetual", "person", "pest", "pet", "petite", "pets", "phobic", "phone", "physical", "picayune", "pick", "pickle", "picture", "pie", "pies", "pig", "pigs", "pin", "pinch", "pine", "pink", "pipe", "piquant", "pizzas", "place", "placid", "plain", "plan", "plane", "planes", "plant", "plantation", "plants", "plastic", "plate", "plausible", "play", "playground", "pleasant", "please", "pleasure", "plot", "plough", "plucky", "plug", "pocket", "point", "pointless", "poised", "poison", "poke", "polish", "polite", "political", "pollution", "poor", "pop", "popcorn", "porter", "position", "possess", "possessive", "possible", "post", "pot", "potato", "pour", "powder", "power", "powerful", "practice", "pray", "preach", "precede", "precious", "prefer", "premium", "prepare", "present", "preserve", "press", "pretend", "pretty", "prevent", "previous", "price", "pricey", "prick", "prickly", "print", "private", "probable", "produce", "productive", "profit", "profuse", "program", "promise", "property", "prose", "protect", "protective", "protest", "proud", "provide", "psychedelic", "psychotic", "public", "puffy", "pull", "pump", "pumped", "punch", "puncture", "punish", "punishment", "puny", "purple", "purpose", "purring", "push", "pushy", "puzzled", "puzzling", "quack", "quaint", "quarrelsome", "quarter", "quartz", "queen", "question", "questionable", "queue", "quick", "quickest", "quicksand", "quiet", "quill", "quilt", "quince", "quirky", "quiver", "quixotic", "quizzical", "rabbit", "rabbits", "rabid", "race", "racial", "radiate", "ragged", "rail", "railway", "rain", "rainstorm", "rainy", "raise", "rake", "rambunctious", "rampant", "range", "rapid", "rare", "raspy", "rat", "rate", "ratty", "ray", "reach", "reaction", "reading", "ready", "real", "realize", "reason", "rebel", "receipt", "receive", "receptive", "recess", "recognise", "recondite", "record", "red", "reduce", "redundant", "reflect", "reflective", "refuse", "regret", "regular", "reign", "reject", "rejoice", "relation", "relax", "release", "relieved", "religion", "rely", "remain", "remarkable", "remember", "remind", "reminiscent", "remove", "repair", "repeat", "replace", "reply", "report", "representative", "reproduce", "repulsive", "request", "rescue", "resolute", "resonant", "respect", "responsible", "rest", "retire", "return", "reward", "rhetorical", "rhyme", "rhythm", "rice", "rich", "riddle", "rifle", "right", "righteous", "rightful", "rigid", "ring", "rings", "rinse", "ripe", "risk", "ritzy", "river", "road", "roasted", "rob", "robin", "robust", "rock", "rod", "roll", "romantic", "roof", "room", "roomy", "root", "rose", "rot", "rotten", "rough", "round", "route", "royal", "rub", "ruddy", "rude", "ruin", "rule", "run", "rural", "rush", "rustic", "ruthless", "sable", "sack", "sad", "safe", "sail", "salt", "salty", "same", "sand", "sassy", "satisfy", "satisfying", "save", "savory", "saw", "scale", "scandalous", "scarce", "scare", "scarecrow", "scared", "scarf", "scary", "scatter", "scattered", "scene", "scent", "school", "science", "scientific", "scintillating", "scissors", "scold", "scorch", "scrape", "scratch", "scrawny", "scream", "screeching", "screw", "scribble", "scrub", "sea", "seal", "search", "seashore", "seat", "second", "second-hand", "secret", "secretary", "secretive", "sedate", "seed", "seemly", "selection", "selective", "self", "selfish", "sense", "separate", "serious", "servant", "serve", "settle", "shade", "shaggy", "shake", "shaky", "shallow", "shame", "shape", "share", "sharp", "shave", "sheep", "sheet", "shelf", "shelter", "shiny", "ship", "shirt", "shiver", "shivering", "shock", "shocking", "shoe", "shoes", "shop", "short", "show", "shrill", "shrug", "shut", "shy", "sick", "side", "sidewalk", "sigh", "sign", "signal", "silent", "silk", "silky", "silly", "silver", "simple", "simplistic", "sin", "sincere", "sink", "sip", "sister", "sisters", "six", "size", "skate", "ski", "skillful", "skin", "skinny", "skip", "skirt", "sky", "slap", "slave", "sleep", "sleepy", "sleet", "slim", "slimy", "slip", "slippery", "slope", "sloppy", "slow", "small", "smart", "smash", "smell", "smelly", "smile", "smiling", "smoggy", "smoke", "smooth", "snail", "snails", "snake", "snakes", "snatch", "sneaky", "sneeze", "sniff", "snobbish", "snore", "snotty", "snow", "soak", "soap", "society", "sock", "soda", "sofa", "soft", "soggy", "solid", "somber", "son", "song", "songs", "soothe", "sophisticated", "sordid", "sore", "sort", "sound", "soup", "sour", "space", "spade", "spare", "spark", "sparkle", "sparkling", "special", "spectacular", "spell", "spicy", "spiders", "spiffy", "spiky", "spill", "spiritual", "spiteful", "splendid", "spoil", "sponge", "spooky", "spoon", "spot", "spotless", "spotted", "spotty", "spray", "spring", "sprout", "spurious", "spy", "squalid", "square", "squash", "squeak", "squeal", "squealing", "squeamish", "squeeze", "squirrel", "stage", "stain", "staking", "stale", "stamp", "standing", "star", "stare", "start", "statement", "station", "statuesque", "stay", "steadfast", "steady", "steam", "steel", "steep", "steer", "stem", "step", "stereotyped", "stew", "stick", "sticks", "sticky", "stiff", "stimulating", "stingy", "stir", "stitch", "stocking", "stomach", "stone", "stop", "store", "stormy", "story", "stove", "straight", "strange", "stranger", "strap", "straw", "stream", "street", "strengthen", "stretch", "string", "strip", "striped", "stroke", "strong", "structure", "stuff", "stupendous", "stupid", "sturdy", "subdued", "subsequent", "substance", "substantial", "subtract", "succeed", "successful", "succinct", "suck", "sudden", "suffer", "sugar", "suggest", "suggestion", "suit", "sulky", "summer", "sun", "super", "superb", "superficial", "supply", "support", "suppose", "supreme", "surprise", "surround", "suspect", "suspend", "swanky", "sweater", "sweet", "sweltering", "swift", "swim", "swing", "switch", "symptomatic", "synonymous", "system", "table", "taboo", "tacit", "tacky", "tail", "talented", "talk", "tall", "tame", "tan", "tangible", "tangy", "tank", "tap", "tart", "taste", "tasteful", "tasteless", "tasty", "tawdry", "tax", "teaching", "team", "tearful", "tease", "tedious", "teeny", "teeny-tiny", "teeth", "telephone", "telling", "temper", "temporary", "tempt", "ten", "tendency", "tender", "tense", "tent", "tenuous", "terrible", "terrific", "terrify", "territory", "test", "tested", "testy", "texture", "thank", "thankful", "thaw", "theory", "therapeutic", "thick", "thin", "thing", "things", "thinkable", "third", "thirsty", "thought", "thoughtful", "thoughtless", "thread", "threatening", "three", "thrill", "throat", "throne", "thumb", "thunder", "thundering", "tick", "ticket", "tickle", "tidy", "tie", "tiger", "tight", "tightfisted", "time", "tin", "tiny", "tip", "tire", "tired", "tiresome", "title", "toad", "toe", "toes", "tomatoes", "tongue", "tooth", "toothbrush", "toothpaste", "toothsome", "top", "torpid", "touch", "tough", "tour", "tow", "towering", "town", "toy", "toys", "trace", "trade", "trail", "train", "trains", "tramp", "tranquil", "transport", "trap", "trashy", "travel", "tray", "treat", "treatment", "tree", "trees", "tremble", "tremendous", "trick", "tricky", "trip", "trite", "trot", "trouble", "troubled", "trousers", "truck", "trucks", "truculent", "true", "trust", "truthful", "try", "tub", "tug", "tumble", "turkey", "turn", "twig", "twist", "two", "type", "typical", "ubiquitous", "ugliest", "ugly", "ultra", "umbrella", "unable", "unaccountable", "unadvised", "unarmed", "unbecoming", "unbiased", "uncle", "uncovered", "understood", "underwear", "undesirable", "undress", "unequal", "unequaled", "uneven", "unfasten", "unhealthy", "uninterested", "unique", "unit", "unite", "unkempt", "unknown", "unlock", "unnatural", "unpack", "unruly", "unsightly", "unsuitable", "untidy", "unused", "unusual", "unwieldy", "unwritten", "upbeat", "uppity", "upset", "uptight", "use", "used", "useful", "useless", "utopian", "utter", "uttermost", "vacation", "vacuous", "vagabond", "vague", "valuable", "value", "van", "vanish", "various", "vase", "vast", "vegetable", "veil", "vein", "vengeful", "venomous", "verdant", "verse", "versed", "vessel", "vest", "victorious", "view", "vigorous", "violent", "violet", "visit", "visitor", "vivacious", "voice", "voiceless", "volatile", "volcano", "volleyball", "voracious", "voyage", "vulgar", "wacky", "waggish", "wail", "wait", "waiting", "wakeful", "walk", "wall", "wander", "wandering", "want", "wanting", "war", "warlike", "warm", "warn", "wary", "wash", "waste", "wasteful", "watch", "water", "watery", "wave", "waves", "wax", "way", "weak", "wealth", "wealthy", "weary", "weather", "week", "weigh", "weight", "welcome", "well-groomed", "well-made", "well-off", "well-to-do", "wet", "wheel", "whimsical", "whine", "whip", "whirl", "whisper", "whispering", "whistle", "white", "whole", "wholesale", "wicked", "wide", "wide-eyed", "wiggly", "wild", "wilderness", "willing", "wind", "window", "windy", "wine", "wing", "wink", "winter", "wipe", "wire", "wiry", "wise", "wish", "wistful", "witty", "wobble", "woebegone", "woman", "womanly", "women", "wonder", "wonderful", "wood", "wooden", "wool", "woozy", "word", "work", "workable", "worm", "worried", "worry", "worthless", "wound", "wrap", "wrathful", "wreck", "wren", "wrench", "wrestle", "wretched", "wriggle", "wrist", "writer", "writing", "wrong", "wry", "x-ray", "yak", "yam", "yard", "yarn", "yawn", "year", "yell", "yellow", "yielding", "yoke", "young", "youthful", "yummy", "zany", "zealous", "zebra", "zephyr", "zesty", "zinc", "zip", "zipper", "zippy", "zonked", "zoo", "zoom"};
    srand(time(0));
    
    clock_t begin=clock();

    while(((int)(clock()-begin)/CLOCKS_PER_SEC)<t)
    {
        r=rand()%2466;
    	x=2;
	    pos;
	    system("cls");
		setcolor(12);
		pos;
		printf("Enter the following words::");
        keyboard(15,20);pos;
		setcolor(15);
        printf("%s",word[r]);
        pos;
        for(int i=0;i<strlen(word[r]);i++)
        {
            char ch;
            setcolor(10);
            while (1) 
       {
            if (_kbhit())
            {
                ch=getche();

            
             break;
            }

            int currentTime = time(NULL);
             if (((int)(clock()-begin)/CLOCKS_PER_SEC)>=t) 
            {
              k=1;  
              break;
            }
        }

        if(k==1)
        break; 
            while(ch!=word[r][i])
        {
                if(ch==8)
				printf(" \b");
				else
					printf("\b \b");
				mistakes++;
                while (1) 
            {
                if (_kbhit())
                {
                    ch=getche();

                
                break;
                }

                int currentTime = time(NULL);
                if (((int)(clock()-begin)/CLOCKS_PER_SEC)>=t) 
                {
                k=1;  
                break;
                }
            }

            if(k==1)
            break;   
        }
        }
        setcolor(15);
        if (k==1)
            break;
        score=score+10;
        words++;
        printf("\n");
    }
int speed=words*60/t;
print_score(speed,score,level,mistakes,words);

}
//..................................................................................................................................
void normal()
{
        int words=0,mistakes=0,score=0,speed,level=3,r,k=0;
    char strings[40][1000]={"No one will come after me","She likes to paint by herself","We went fishing after school","You are very lazy","You do not teach your cat tricks","I would like to help you","I will get myself a coffee","I will not take it from you","He does not goes to gym every day","He is my best friend","I learnt English by myself","Alex is not telling the truth","They killed him","You are not an engineer","My mom likes to paint by herself","You will not come with me","I really need someone","This was a threat to us","I told my father that I wanted to go to London","I can not come home early today","Brazil is not a country in Europe","She learned to read by herself","These are for you","I want to do something","You should go take it from him","They speak English in USA","I love you","She cook for you","The dogs belong to them","We borrowed her car","I have not failed","She is a mechanical engineer","I will take it from you","My father would not let us buy a new computer","They are the smartest kids here","We do not have a house","I have got a sister","I lost my wallet last week","Today we will come","I will help you"};
    clock_t begin=clock();
    
	x=2;
	
    while(1)
    {
        srand(time(0));
        r=rand()%40;
		system("cls");
		x=2;
        keyboard(15,20);
		setcolor(12);
		pos;
		printf("Enter the below sentence:");
		setcolor(1);
		pos;
		pos;
		pos;
		printf("%s",strings[r]);
		keyboard(15,20);
		gotoxy(33,x-1);
        for (int j=0;j<strlen(strings[r]);j++)
        {
            char ch;
            setcolor(10);
        while (1) 
        {
            if (_kbhit())
            {
                ch=getche();

            
             break;
            }

            int currentTime = time(NULL);
             if (((int)(clock()-begin)/CLOCKS_PER_SEC)>=t) 
            {
              k=1;  
              break;
            }
        }

        if(k==1)
        break; 
            if(ch==32&&strings[r][j]==ch)
            words++;
            if (strings[r][j]!=ch)
            {
                if(ch!=8)
                {
                    setcolor(1);
                printf("\b%c\b",strings[r][j]);
                    j=j-1;
                }
                else
                {
                    setcolor(1);
                    if (j==0)
                    printf(" ");
                    else
                    printf("%c\b",strings[r][j-1]);
                    if(j==0)
                    j=j-1;
                    else
                    j=j-2;
                }
                mistakes++;
            }
        }
        if(k==0){
        printf("\n");
        setcolor(15);
        words++;
        score=score+10;
        }
        else break;
    }
    speed=words*60/t;
	print_score(speed,score,level,mistakes,words);

}
//....................................................................................................................................
void hard()
{
	int words=0,mistakes=0,score=0,speed,level=4,r,k=0;
    char strings[4][1500]={"It was the first exam of final term. All the students were looking very nervous, as the exam was of history and it was just going to start. All the students were worried about it but Raman was worried the most as he had not studied whole year and now it's exam time. Liya (his friend) asked him that why is he so worried. But he didn't answer becayse many question were now rising in his mind, like, Why he didn't study? Why he just wasted his time in playing games and watching tv? Why he didn't listen to his parents and teachers? But now there is 'No use of crying over the spilt milk'.","I doubt I can. It is a major part of many, many words. Omitting it is as hard as making muffins without flour. It is as hard as spitting without saliva, napping without a pillow, driving a train without tracks, sailing to Russia without a boat, washing your hands without soap, or shitting without a butt. And, anyway, what would I gain? An award? A cash bonus? Bragging rights? Why should I strain my brain? It is not worth doing. Now, a grammatical paragraph without commas: that would wow most folks on Quora, don't you think? Could you do it? If so, I tip my hat to you or I would if I had a hat. Or, how about a paragraph without punctuation?","Ramanujan (literally, 'younger brother of Rama', a Hindu deity) was born on 22 December 1887 into a Tamil Brahmin Iyengar family in Erode, in present-day Tamil Nadu.His father, Kuppuswamy Srinivasa Iyengar, originally from Thanjavur district, worked as a clerk in a sari shop.His mother, Komalatammal, was a housewife and sang at a local temple. They lived in a small traditional home on Sarangapani Sannidhi Street in the town of Kumbakonam.The family home is now a museum. When Ramanujan was a year and a half old, his mother gave birth to a son, Sadagopan, who died less than three months later.","C. V. Raman was born in Tiruchirappalli in the Madras Presidency of British India (now Tiruchirapalli, Tamil Nadu, India) to Tamil Brahmin parents, Chandrasekhara Ramanathan Iyer and Parvathi Ammal. He was the second of eight siblings. His father was a teacher at a local high school, and earned a modest income. He recalled: 'I was born with a copper spoon in my mouth. At my birth my father was earning the magnificent salary of ten rupees per month!' In 1892, his family moved to Visakhapatnam (then Vizagapatam or Vizag) in Andhra Pradesh as his father was appointed to the faculty of physics at Mrs A.V. Narasimha Rao College."};
    clock_t begin=clock();
    
	x=2;
	
    while(1)
    {
        srand(time(0));
        r=rand()%4;
            setcolor(12);
            keyboard(15,20);pos;
			setcolor(12);
        printf("Enter the below paragraph:");
        pos;
        setcolor(1);
        for(int i=0;i<strlen(strings[r]);i++)
        {
            if(i%90==0)
            pos;
            printf("%c",strings[r][i]);
        }
        
		gotoxy(33,x-1);
        x=4;
        int flag=0;
        for (int j=0;j<strlen(strings[r]);j++)
        {
            if(j%90==0 && flag==0)
            pos;
            char ch;
            setcolor(10);
            while (1) 
            {
                if (_kbhit())
                {
                    ch=getche();

                
                break;
                }

                int currentTime = time(NULL);
                if (((int)(clock()-begin)/CLOCKS_PER_SEC)>=t) 
                {
                k=1;  
                break;
                }
            }

            if(k==1)
            break; 
            if(ch==32&&strings[r][j]==ch)
            words++;
            if (strings[r][j]!=ch)
            {
                if(ch!=8)
                {
                    setcolor(1);
                printf("\b%c\b",strings[r][j]);
                
                    if(j%90==0)
                    flag=1;
                    else flag=0;
                    j=j-1;
                }
                else
                {
                    setcolor(1);
                    if (j==0)
                    {
                    printf(" ");
                    flag=1;
                    }
                    else if (j%90==0&&j>=90)
                    {
                        gotoxy(122,x-2);
                        printf("%c\b",strings[r][j-1]);
                        x=x-1;
                    }
                    else
                    {
                        printf("%c\b",strings[r][j-1]);
                        if((j%90==0)||(j%90==1)){
                        flag=1;}
                        else flag=0;
                    }
                    if(j==0)
                    j=j-1;
                    else
                    j=j-2;
                }
                mistakes++;
            }
        }
        if(k==0){
        printf("\n");
        setcolor(15);
        words++;

        }
        else break;
    }
    speed=words*60/t;
	print_score(speed,score,level,mistakes,words);
}
//..................................................................................................................
//keyboard functions
void arectangle(int x,int y, int l,int b,int color,char str[15])//printing keys

{
    int i,j;
    setcolor(color);
    for(i=0;i<b;i++)
    {
        gotoxy(x,y+i);
        for(j=0;j<l;j++)
        {
            printf("%c",219);
        }
    }
    setbgcolor(color);
    gotoxy(x,y+1);
    printf("%s",str);
    setbgcolor(0);
    setcolor(15);
}
void leter(struct letters alpha)//printing letters

{
    int i,j;
    gotoxy(alpha.X,alpha.Y);
    for(j=0;j<3;j++)
    {
        setcolor(alpha.bgcolor);

        for (i=0;i<7;i++)
        {
            printf("%c",219);
        }
        gotoxy(alpha.X,alpha.Y+j+1);

    }

            setbgcolor(alpha.bgcolor);
    setcolor(alpha.color);
    gotoxy((alpha.X)+3,(alpha.Y)+1);
    printf("%c",alpha.a);
    gotoxy(alpha.X +1,alpha.Y);
    printf("%c",alpha.a2);
    setbgcolor(0);
    setcolor(15);

}
void keyboard(int x,int y)///keyboard layout setup
{
    struct _COORD size = {200,48};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
    
    int i,j,k;
    int l=7,b=3;
    int x1=x+(3*l/2),
    x2=x+(2*l-1),
    x3=x+2*l+3;

    
    struct letters keys[]={
        [0]={x,y,'`',0,11,'~'},
        [1]={x+l+1,y,'1',0,11,'!'},
        [2]={x+2*(l+1),y,'2',0,12,'@'},
        [3]={x+3*(l+1),y,'3',0,14,'#'},
        [4]={x+4*(l+1),y,'4',0,10,'$'},
        [5]={x+5*(l+1),y,'5',0,10,'%'},
        [6]={x+6*(l+1),y,'6',0,10,'^'},
        [7]={x+7*(l+1),y,'7',0,10,'&'},
        [8]={x+8*(l+1),y,'8',0,14,'*'},
        [9]={x+9*(l+1),y,'9',0,12,'('},
        [10]={x+10*(l+1),y,'0',0,11,')'},
        [11]={x+11*(l+1),y,'-',0,11,'_'},
        [12]={x+12*(l+1),y,'=',0,11,'+'},
        [13]={x1,y+4,'Q',0,11},
        [14]={x1+l+1,y+4,'W',0,12},
        [15]={x1+2*(l+1),y+4,'E',0,14},
        [16]={x1+3*(l+1),y+4,'R',0,10},
        [17]={x1+4*(l+1),y+4,'T',0,10},
        [18]={x1+5*(l+1),y+4,'Y',0,10},
        [19]={x1+6*(l+1),y+4,'U',0,10},
        [20]={x1+7*(l+1),y+4,'I',0,14},
        [21]={x1+8*(l+1),y+4,'O',0,12},
        [22]={x1+9*(l+1),y+4,'P',0,11},
        [23]={x1+10*(l+1),y+4,'[',0,11,'{'},
        [24]={x1+11*(l+1),y+4,']',0,11,'}'},
        [25]={x1+12*(l+1),y+4,92,0,11,'|'},
        [26]={x2,y+8,'A',0,11},
        [27]={x2+l+1,y+8,'S',0,12},
        [28]={x2+2*(l+1),y+8,'D',0,14},
        [29]={x2+3*(l+1),y+8,'F',0,10},
        [30]={x2+4*(l+1),y+8,'G',0,10},
        [31]={x2+5*(l+1),y+8,'H',0,10},
        [32]={x2+6*(l+1),y+8,'J',0,10},
        [33]={x2+7*(l+1),y+8,'K',0,14},
        [34]={x2+8*(l+1),y+8,'L',0,12},
        [35]={x2+9*(l+1),y+8,';',0,11,':'},
        [36]={x2+10*(l+1),y+8,39,0,11,'"'},
        [37]={x3,y+12,'Z',0,11},
        [38]={x3+l+1,y+12,'X',0,12},
        [39]={x3+2*(l+1),y+12,'C',0,14},
        [40]={x3+3*(l+1),y+12,'V',0,10},
        [41]={x3+4*(l+1),y+12,'B',0,10},
        [42]={x3+5*(l+1),y+12,'N',0,10},
        [43]={x3+6*(l+1),y+12,'M',0,10},
        [44]={x3+7*(l+1),y+12,',',0,14,'<'},
        [45]={x3+8*(l+1),y+12,'.',0,12,'>'},
        [46]={x3+9*(l+1),y+12,'/',0,11,'?'},


    };
    for(i=0;i<47;i++)
    {
            leter(keys[i]);
    }
    arectangle(x,y+12,x3-1-x,3,11,"  SHIFT");
    arectangle(x3+10*(l+1),y+12,x1+23-x3,3,11,"        SHIFT");
    arectangle(x,y+4,9,3,11,"  TAB");
    arectangle(x+104,y,9,3,11,"BACKSPACE");
    arectangle(x2+88,y+8,12,3,11,"  ENTER");
    arectangle(x,y+8,12,3,11," CAPS LOCK");
    arectangle(x3+16,y+16,42,3,13,"                  SPACE");
    printf("\n\n\n");
	

}