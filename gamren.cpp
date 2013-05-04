#include<iostream.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>


void go_top(void);
void go_down(void);
void go_left(void);
void go_right(void);
int spawn_location(void);
void spawn_people(void);
void print_opt(int);
void print_opt_humans(int);
void print_opt_directions(int);
void print_opt_tlo(int);
void take_decision(void);
void set_spl_dialo(void);
int check_spl_dialo(int);
void run_spl_dialo(int);
void spl_dialo1(void);
void spl_dialo2(void);
void spl_dialo3(void);
void spl_dialo4(void);
void spl_dialo5(void);
void endline(void);
void name_personality(void);
void bday_personality(void);
void start(void);
void end(void);
void start_get_names(void);
void get_prized_pos(void);

unsigned long code1, code2, code3, code4, code5, finalcode;
int sc1, sc2, sc3, sc4, sc5;
int rnum[16];

struct rooms {
 int id;
 char name[50];
 char desc[500];
 int left;
 int right;
 int top;
 int down;
};

struct people {
 int id;
 int iid;
 char name[50];
 char dialo[500];
 int spl_dialo_id;
};

struct personality {
 char heading[100];
 char desc[1000];
};

personality per1[16] = {
  {"The Duty Fulfiller", "Serious and quiet, interested in security and peaceful living. Extremely thorough, responsible, and dependable. Well-developed powers of concentration. Usually interested in supporting and promoting traditions and establishments. Well-organized and hard working, they work steadily towards identified goals. They can usually accomplish any task once they have set their mind to it."},
  {"The Mechanic", "Quiet and reserved, interested in how and why things work. Excellent skills with mechanical things. Risk-takers who they live for the moment. Usually interested in and talented at extreme sports. Uncomplicated in their desires. Loyal to their peers and to their internal value systems, but not overly concerned with respecting laws and rules if they get in the way of getting something done. Detached and analytical, they excel at finding solutions to practical problems."},
  {"The Nurturer", "Quiet, kind, and conscientious. Can be depended on to follow through. Usually puts the needs of others above their own needs. Stable and practical, they value security and traditions. Well-developed sense of space and function. Rich inner world of observations about people. Extremely perceptive of other's feelings. Interested in serving others."},
  {"The Artist", "Quiet, serious, sensitive and kind. Do not like conflict, and not likely to do things which may generate conflict. Loyal and faithful. Extremely well-developed senses, and aesthetic appreciation for beauty. Not interested in leading or controlling others. Flexible and open-minded. Likely to be original and creative. Enjoy the present moment."},
  {"The Protector", "Quietly forceful, original, and sensitive. Tend to stick to things until they are done. Extremely intuitive about people, and concerned for their feelings. Well-developed value systems which they strictly adhere to. Well-respected for their perserverence in doing the right thing. Likely to be individualistic, rather than leading or following."},
  {"The Idealist", "Quiet, reflective, and idealistic. Interested in serving humanity. Well-developed value system, which they strive to live in accordance with. Extremely loyal. Adaptable and laid-back unless a strongly-held value is threatened. Usually talented writers. Mentally quick, and able to see possibilities. Interested in understanding and helping people."},
  {"The Scientist", "Independent, original, analytical, and determined. Have an exceptional ability to turn theories into solid plans of action. Highly value knowledge, competence, and structure. Driven to derive meaning from their visions. Long-range thinkers. Have very high standards for their performance, and the performance of others. Natural leaders, but will follow if they trust existing leaders."},
  {"The Thinker", "Logical, original, creative thinkers. Can become very excited about theories and ideas. Exceptionally capable and driven to turn theories into clear understandings. Highly value knowledge, competence and logic. Quiet and reserved, hard to get to know well. Individualistic, having no interest in leading or following others."},
  {"The Doer", "Friendly, adaptable, action-oriented. \"Doers\" who are focused on immediate results. Living in the here-and-now, they're risk-takers who live fast-paced lifestyles. Impatient with long explanations. Extremely loyal to their peers, but not usually respectful of laws and rules if they get in the way of getting things done. Great people skills."},
  {"The Guardian", "Practical, traditional, and organized. Likely to be athletic. Not interested in theory or abstraction unless they see the practical application. Have clear visions of the way things should be. Loyal and hard-working. Like to be in charge. Exceptionally capable in organizing and running activities. \"Good citizens\" who value security and peaceful living."},
  {"The Performer", "People-oriented and fun-loving, they make things more fun for others by their enjoyment. Living for the moment, they love new experiences. They dislike theory and impersonal analysis. Interested in serving others. Likely to be the center of attention in social situations. Well-developed common sense and practical ability."},
  {"The Caregiver", "Warm-hearted, popular, and conscientious. Tend to put the needs of others over their own needs. Feel strong sense of responsibility and duty. Value traditions and security. Interested in serving others. Need positive reinforcement to feel good about themselves. Well-developed sense of space and function."},
  {"The Inspirer", "Enthusiastic, idealistic, and creative. Able to do almost anything that interests them. Great people skills. Need to live life in accordance with their inner values. Excited by new ideas, but bored with details. Open-minded and flexible, with a broad range of interests and abilities."},
  {"The Giver", "Popular and sensitive, with outstanding people skills. Externally focused, with real concern for how others think and feel. Usually dislike being alone. They see everything from the human angle, and dislike impersonal analysis. Very effective at managing people issues, and leading group discussions. Interested in serving others, and probably place the needs of others over their own needs."},
  {"The Visionary", "Creative, resourceful, and intellectually quick. Good at a broad range of things. Enjoy debating issues, and may be into \"one-up-manship\". They get very excited about new ideas and projects, but may neglect the more routine aspects of life. Generally outspoken and assertive. They enjoy people and are stimulating company. Excellent ability to understand concepts and apply logic to find solutions."},
  {"The Executive", "Assertive and outspoken - they are driven to lead. Excellent ability to understand difficult organizational problems and create solid solutions. Intelligent and well-informed, they usually excel at public speaking. They value knowledge and competence, and usually have little patience with inefficiency or disorganization."}
};

personality per2[5] = {
  {"Openness to experience", "Openness is a general appreciation for art, emotion, adventure, unusual ideas, imagination, curiosity, and variety of experience. People who are open to experience are intellectually curious, appreciative of art, and sensitive to beauty. They tend to be, when compared to closed people, more creative and more aware of their feelings. They are more likely to hold unconventional beliefs. "},
  {"Conscientiousness", "Conscientiousness is a tendency to show self-discipline, act dutifully, and aim for achievement against measures or outside expectations. The trait shows a preference for planned rather than spontaneous behavior. It influences the way in which we control, regulate, and direct our impulses."},
  {"Extraversion", "Extraversion is characterized by positive emotions, surgency, and the tendency to seek out stimulation and the company of others. The trait is marked by pronounced engagement with the external world. Extraverts enjoy being with people, and are often perceived as full of energy."},
  {"Agreeableness", "Agreeableness is a tendency to be compassionate and cooperative rather than suspicious and antagonistic towards others. The trait reflects individual differences in general concern for social harmony. Agreeable individuals value getting along with others. They are generally considerate, friendly, generous, helpful, and willing to compromise their interests with others. Agreeable people also have an optimistic view of human nature."},
  {"Neuroticism", "Neuroticism is the tendency to experience negative emotions, such as anger, anxiety, or depression. It is sometimes called emotional instability, or is reversed and referred to as emotional stability."},
};

people p[15] = {
  {0, 10, "", "Hey there! Hope you are having a nice time at this school. Oh, by the way, I recommend noting down any digits people give you...\n", 0},
  {1, 20, "", "Why, hello there! You seem to be excited! You must be looking for something, huh? Tell you what, keep looking for a box. People say it contains your deepest desires.\n", 0},
  {2, 30, "", "Hi there, friend! Have you checked out the secret passageway to Garuda Mall? It's wicked!\n", 0},
  {3, 40, "", "Humpty dumpty ... Lol, sorry for that! I have to memorize and entire poem.\n", 0},
  {4, 50, "", "I.. I.. I like you! Are you enjoying yourself? I bet you are! You should check out the deeper grounds, it\'s a wonderful place!\n", 0},
  {5, 60, "", "Hey, wanted to let you know that you will need a code to open the box containing your desires. Remember, the code is always in presence.\n", 0},
  {6, 70, "", "Hello! Do you want to know about codes? They are usually 5 digit long!\n", 0},
  {7, 80, "", "Hey buddy! I feel so nostalgic looking at you, I was in the same position as you! Keep talking to people! You might receive some important codes!\n", 0},
  {8, 90, "", "The box of code is a wicked box. Remember, keep trying various combinations of the digits you receive...\n", 0},
  {9, 100, "", "I've heard people say that the code box likes only 5 digits together! No more, no less!\n", 0},
  {10, 110, "", "You should check out the various labs we have at our school, truly amazing stuff!\n", 0},
  {11, 120, "", "I remember my first day here, walking into that Hall, memories, oh memories...\n", 0},
  {12, 130, "", "There are some funny people around who give personality quizzes! You should try them sometime.\n", 0},
  {13, 140, "", "There\'s a funny kid in the school, he keeps talking about Pokemon, in fact, he asks everyone if they like it! Such a kid.\n", 0},
  {14, 150, "", "I wanted to give you some advice, whether or not you can never become great at something, you can always become better at it. Don't ever forget that! And don’t say \"I’ll never be good\". You can become better! And one day you’ll wake up and you’ll find out how good you actually became.\n", 0}
};

rooms r[36] = {
  {0, "KVASC", "Welcome to the land of great opportunities!", -1, -1, 1, -1},
  {1, "Gate", "Here is where it all begins. Hope you have everything in your backpack!", -1, -1, 2, 0},
  {2, "Road 1", "The entry road which leads to further destinations.", 3, 5, 4, 1},
  {3, "Canteen", "Canteen is the place where you'll want to spend all your time, yummy samosas!", -1, 2, -1, -1},
  {4, "Road 3", "", -1, 11, -1, -1},
  {5, "Road 2", "", 2, 6, 8, -1},
  {6, "Deeper Grounds", "Legend says this is the place of genuine inspiration. A place to clear your thoughts and perhaps, build a program.", 5, -1, -1, 7},
  {7, "Trees", "\"Tree touch!\" is what the kids play all day here. Lovely sights as well, if you know what I mean \;\)", -1, -1, 6, -1},
  {8, "Hall", "The great Hall of KVASC. Many a first impression of the school is formed here. A mini-KVASC, perhaps.", 11, 9, 12, 5},
  {9, "Grounds", "The kid brother of deeper Grounds. Here you will mostly see students playing football, cricket, basketball and what-have-you.", 8, -1, 10, -1},
  {10, "Yoga Hall", "The Yoga Hall is a symbolic of the student rebellion that took place in this school two years ago. If you have a hawk eye, then you may know what I\'m talking about!", -1, -1, -1, 9},
  {11, "Corridor A", "", 4, 8, 15, 13},
  {12, "Corridor B", "", 14, 16, 18, 8},
  {13, "Class I", "Little tots having a fun time.", -1, -1, 11, -1},
  {14, "Corridor C", "", -1, 12, 17, 19},
  {15, "Class II", "Aww, these kids are so cute!", -1, -1, -1, 11},
  {16, "Class III", "There class III students are going for a picnic today!", 12, -1, -1, -1},
  {17, "Class IV", "The class where teachers find it very hard to control kids!", -1, -1, -1, 14},
  {18, "Corridor D", "", 26, 20, 23, 12},
  {19, "Class V", "Middle school kids, about to become teenagers are wreck havoc! Haha!", -1, -1, 14, -1},
  {20, "Class VI", "Maturity is beginning to take root...", 18, -1, -1, -1},
  {21, "Hidden Passageway", "OMG WHAT HAVE YOU FOUND????", 22, -1, -1, 24},
  {22, "Garuda Mall", "GARUDA!!!!", -1, 21, -1, -1},
  {23, "Corridor E", "", 25, 24, 29, 18},
  {24, "Toilet", "Funny writings on the wall, and toxic gases all around.", 23, 35, 21, 34},
  {25, "Corridor F", "", 28, 23, 33, 27},
  {26, "Class VII", "The class where kids are very excited to participate in various activities.", -1, 18, -1, -1},
  {27, "Class VIII", "Very naughty class.", -1, -1, 25, -1},
  {28, "Class IX", "Exceptionally disobedient class, and there\'s nothing teachers can do about it.", -1, -1, 25, -1},
  {29, "Corridor G", "", 32, 30, 31, 23},
  {30, "Physics Lab", "More than a mere place in the back of the school, the laboratory is the place where physics students do physics. It is in the laboratory that physics students learn to practice the activities of scientists - asking questions, performing procedures, collecting data, analyzing data, answering questions, and thinking of new questions to explore.", 29, -1, -1, -1},
  {31, "Chemistry Lab", "A little room in the back of the school, Chemistry Lab is a room of wonders and all about performing various chemical reactions.", -1, -1, -1, 29},
  {32, "Biology Lab", "All you\'ll see here is a bunch of microscopes and lots of funny things kept in jars filled with various liquids!", -1, 29, -1, -1},
  {33, "Class X", "Looks like they\'ve gone out to play...", -1, -1, -1, 25},
  {34, "Class XI", "Ambitious teenagers having a fun time.", -1, -1, 24, -1},
  {35, "Class XII", "Everyone looks very serious.", 24, -1, -1, -1}
};

char prized[100];

int playerstatus = 0;
int nnn = 0;
int curr;
int tchestlo;

void main() {
 //int tchest[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 code1 = code2 = code3 = code4 = code5 = finalcode = 0;
 sc1 = sc2 = sc3 = sc4 = sc5 = -1;
 randomize();
 set_spl_dialo();
 for (int o = 0; o < 15; o++) {
  rnum[o] = random(35) + 1;
 }
 randomize();
 tchestlo = r[random(36)].id;
 start();
 while(!playerstatus) {
  spawn_location();
  spawn_people();
  print_opt(curr);
  take_decision();
  endline();
 }
 end();
}

void start(void) {
 int der;
 cout << "\nHello and welcome to the game of SCHOOL HUNT!";
 cout << "\nFirst of all, I'd like to get all your names! Please enter 15 names!: \n";
 start_get_names();
 cout << "\nAlright, now please enter your most prized possession!\n";
 get_prized_pos();
 cout << "\n\nOH DAMN! I hid your favourite thing in the school! Mwahahahahahahahahahahahahahaha!";
 cout << "\n\nNow the only way to retrieve it is to transform yourself into a digital person and explore the glorius expanse of KVASC!";
 cout << "\n\nAre you ready for the biggest challenge of your life?! \nEnter 1 for yes and 0 for no!\n";
 cin >> der;
 if (der) {
  cout << "\n\nAlright, remember keep talking to the people present inside... you never know how they might help you!";
  cout << "\n\nAND OFF YOU GO!\n\n";
 }
 else cout << "\nMwahahaha, do you think you have a choice? OFF YOU GO!\n\n";
}

void start_get_names(void) {
 for (int d = 0; d < 15; d++) {
  cin >> p[d].name;
 }
 randomize();
 cout << "\n\nWow, what a lovely name " << p[random(15)].name << " is! In fact, all the names are wonderful.";
 cout << "\n\nThank you for your co-operation!";  
}

void get_prized_pos(void) {
  cin.getline(prized, 100);
  cin.getline(prized, 100);
  cout << "\nThat\'s a nice, nice thing... Hmm...";
}

void end(void) {
  int len;
  cout << "\n\nThat is it, you have finally found your coveted prize. You truly deserve it.";
  cout << "Here's your ";
  len = strlen(prized);
  cout.write(prized, len); cout << "\n";
  cout << "\n\nVery rarely do I find a young man ever so determined to win. I am deeply in thought about your aspirations, and your favourite quote. May you be the man you see yourself in another ten years.";
  cout << "\nGood luck!";
}

void set_spl_dialo(void) {
 randomize();
 int cc = 0;
 while(cc != 5)  {
  for (int x = 1; x <= 5; x++) {
	p[random(15)].spl_dialo_id = x;
  }
  for (x = 0; x < 15; x++) {
	if (p[x].spl_dialo_id) cc++;
  }
  if (cc < 5) {
	for (x = 0; x < 15; x++) {
	 p[x].spl_dialo_id = 0;
	}
  }
 }
}

int check_spl_dialo(int x) {
 if (p[x].spl_dialo_id)
  return 1;
 else
  return 0;
}

void run_spl_dialo(int x) {
 switch(p[x].spl_dialo_id) {
  case 1 : spl_dialo1(); break;
  case 2 : spl_dialo2(); break;
  case 3 : spl_dialo3(); break;
  case 4 : spl_dialo4(); break;
  case 5 : spl_dialo5(); break;
 }
}

int spawn_location(void) {
 curr = nnn;
 cout << r[curr].name << "\n";
 cout << r[curr].desc << "\n";
 return 0;
}

void spawn_people(void) {
 for (int z = 0; z < 15; z++) {
  if (nnn == rnum[z]) {
	 cout << "\nLooks like there is " << p[z].name << " present here. Go have a chat, perhaps? \n";
  }
 }
}

void print_opt(int crr) {
 cout << "\n\nActions:\n";
 print_opt_humans(crr);
 print_opt_directions(crr);
 print_opt_tlo(crr);
}

void print_opt_humans(int crr) {
 //cout << "\n\n";
 for (int l = 0; l < 15; l++) {
  if (crr == rnum[l]) {
	 cout << "Go talk to " << p[l].name << " (Enter: " << p[l].iid << ")\n";
  }
 }

}

void print_opt_directions(int crr) {
 //cout << "\n";
 if (r[crr].top >= 0)
  cout << "Go up to " << r[r[crr].top].name << " (Enter: 1)" << "\n";
 if (r[crr].down >= 0)
  cout << "Go down to " << r[r[crr].down].name << " (Enter: 2)" << "\n";
 if (r[crr].left >= 0)
  cout << "Go left to " << r[r[crr].left].name << " (Enter: 3)" << "\n";
 if (r[crr].right >= 0)
  cout << "Go right to " << r[r[crr].right].name << " (Enter: 4)" << "\n";
}

void print_opt_tlo(int crr) {
 if(crr == tchestlo)
  cout << "There's a funny box here. Enter 999 to open it.";
}

void take_decision(void) {
 int dec;
 cout << "\nEnter your action: ";
 cin >> dec;
 cout << "\n\n";
 if (dec < 5) {
  switch(dec) {
  case 1 : go_top();
				  break;
  case 2 : go_down();
				  break;
  case 3 : go_left();
				  break;
  case 4 : go_right();
				  break;
  default : cout << "Wrong option";
				  exit(0);
  }
 }
 else if (!(dec%10)) {
  int g;
  for (g = 0; g < 15; g++) {
	 if (dec == p[g].iid) {
		cout << "\n" << p[g].name << ": " << p[g].dialo << "\n";
		break;
	 }
  }
  if (check_spl_dialo(g)) {
	 run_spl_dialo(g);
  }
 }
 else if (dec == 999) {
  int lolcode = 0;
  cout << "\nThis box needs a code to be opened. Enter the code: ";
  cin >> lolcode;
  if (lolcode == finalcode) {
	playerstatus = 1;
  }
  else cout << "\nTry again later.";
 }
 else cout << "WRONG!";
}

void go_top(void) {
 nnn = r[nnn].top;
}

void go_down(void) {
 nnn = r[nnn].down;
}

void go_left(void) {
 nnn = r[nnn].left;
}

void go_right(void) {
 nnn = r[nnn].right;
}

void spl_dialo1(void) {
  // name
  int decn, len;
  char fname[50];
  char lname[50];
  cout << "\n\nHey, by the way, I was wondering if you'd like to run a character analysis, sort of a horoscope.. Enter 1 for yes, 0 for no: ";
  cin >> decn;
  if (decn) {
	sc1++;
	cout << "\nCool! Enter your first name: ";
	cin.getline(fname, 50);
	cin.getline(fname, 50);
	cout << "\nNice! Now enter your last name: ";
	cin.getline(lname, 50);
	len = strlen(fname) + strlen(lname);
	if (!sc1) {
	 if (len%10) code1 = len%10;
	 else code1 = 5;
	 finalcode += code1*10000;
	}
	cout << "\nAlright, here's what your name indicates: ";
	name_personality();
	cout << "\n\nHey, this personality machine gave out this digit: " << code1 << ". Might be useful, maybe \;\)";
	cout << "\nNice talking to you! Cya later!";
  }
  else cout << "\nOh, ok, some time later then! Cya!";
}

void spl_dialo2(void) {
  // dob
  int decn, bdte, bmte, bete, len;
  cout << "\nDude, I've got this cool personality machine which tells you about you via your date of birth! Wanna give it a try? Enter 1 for yes, 0 for no: ";
  cin >> decn;
  if (decn) {
	sc2++;
	cout << "\nAwesome! Enter the date you were born on (only the date not month/year): ";
	cin >> bdte;
	cout << "\nGreat, now enter the month you were born on (numerically): ";
	cin >> bmte;
	cout << "\nWe are getting there! Enter the year you were born on: ";
	cin >> bete;
	len = bdte + bmte + bete;
	if (!sc2) {
	 if (len%10) code2 = len%10;
	 else code2 = 6;
	 finalcode += code2*1000;
	}
	cout << "\nNice! Here's what your date of birth indicates: ";
	bday_personality();
	cout << "\n\nOkay, something weird just happened. This machine gave out this digit! : " << code2 << ". Wonder if that's useful...";
	cout << "\nSee you around! Bye";
  }
  else cout << "\nHaha, alright, maybe some other day. Cya then!";
}

void spl_dialo3(void) {
  // future aspiration
  int decn, len;
  char ipara[1000];
  cout << "\nYou know, I was wondering what your future aspirations are. Do you wanna talk about it? Enter 1 for yes, 0 for no: ";
  cin >> decn;
  if (decn) {
	sc3++;
	cout << "\n\nAlright! Type away...  ";
	cin.getline(ipara, 1000);
   cin.getline(ipara, 1000);
	len = strlen(ipara);
	if (!sc3) {
	 if (len%10) code3 = len%10;
	 else code3 = 7;
	 finalcode += code3*100;
	}
	cout << "\n\nWow, that was truly inspirational! Hope you achieve that goal of yours! Funny, some digit popped into my head! It is " << code3 << "! Might be of some use...";
	cout << "\nYou've given me some thinking to do, I'll talk to you later.";
  }
  else cout << "\nOkay, talk to you later then.";
}

void spl_dialo4(void) {
  // fav quote
  int len;
  char fqt[200];
  cout << "\nBuddy, what is your favourtie quote?\n";
  sc4++;
  cin.getline(fqt, 200);
  cin.getline(fqt, 200);
  len = strlen(fqt);
  if (!sc4) {
	if (len%10) code4 = len%10;
	else code4 = 8;
	finalcode += code4*10;
  }
  cout << "\nHoly cow, that's deep! Love hearing your thoughts!";
  cout << "\n\nHey, something fell down. Hmm, it is a piece of paper and it has " << code4 << " written over it. Lol weird";
  cout << "\nOkay, cya!";
}

void spl_dialo5(void) {
 // pokemon
 int dec;
 cout << "\nYou know, I love Pokemon! It's awesome. Do you like pokemon? Enter 1 for yes, 0 for no: ";
 sc5++;
 cin >> dec;
 if (!sc5) {
  code5 = dec;
  finalcode += code5;
 }
 if (dec) cout << "\nHaha, I know right! It's so great.";
 else cout << "\nWell, you're one weird fella!";
 cout << "\nBy the way, if some one asks you for some code number, remember that the last digit of the code number is going to be the one you entered just now...";
 cout << "\nGood day and bye!";
}

void name_personality(void) {
 randomize();
 int onm;
 onm = random(16);
 cout << "\n\n" << per1[onm].heading << "\n";
 cout << "\n" << per1[onm].desc << "\n\n"; 
}

void bday_personality(void) {
 randomize();
 int rty;
 rty = random(5);
 cout << "\n\n" << per2[rty].heading << "\n";
 cout << "\n" << per2[rty].desc << "\n\n";
}

void endline(void) {
 cout << "\n________________________________________________________________________\n\n";
}