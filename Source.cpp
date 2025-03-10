//#include<iostream>
//#include<string>
//#include"mystack.h"
//#include"myqueue.h"
//#include<ctime>
//#include<sstream>
//#include"myvector.h"
//#include"mylist.h"
//using namespace std;
//
//class Edge_Status
//{
//public:
//	string Status;
//	string Relationship_Type;
//	string Name;
//	Edge_Status() {}
//	Edge_Status(string status,string relationship_type,string name)
//	{
//		Status = status;
//		Relationship_Type = relationship_type;
//		Name = name;
//	}
//	void setStatus(string& status)
//	{
//		Status = status;
//	}
//	void setRelationshipType(string& relationship_Type)
//	{
//		Relationship_Type = relationship_Type;
//
//	}
//	string getStatus()
//	{
//		return Status;
//	}
//	string getRelationshipType()
//	{
//		return Relationship_Type;
//	}
//	void setValue(string& status,string& relationship_Type,string&Target)
//	{
//		setStatus( status);
//		setRelationshipType( relationship_Type);
//		setName(Target);
//	}
//	void getValue()
//	{
//		cout << "Status :: " << Status<<endl;
//		cout << "Relationship Type :: " << Relationship_Type << endl;
//	}
//	void setName(string name)
//	{
//		this->Name = name;
//	}
//	string getName()
//	{
//		return Name;
//	}
//};
//class Post
//{
//public:
//	string Post_Content;
//	string Post_Time;
//	Post(string Post_Content, string Post_Time)
//	{
//		this->Post_Content = Post_Content;
//		this->Post_Time = Post_Time;
//	}
//	void addPost(string Post_Content, string Post_Time)
//	{
//		this->Post_Content = Post_Content;
//		this->Post_Time = Post_Time;
//	}
//	void showPost()
//	{
//		cout << "Post Content :: " << Post_Content << endl;
//		cout << "Post Time :: " << Post_Time;
//		cout << endl;
//	}
//};
//class UserProfile
//{
//public:
//	string Name;
//	double Password;
//	string City_Name;
//	size_t Time;
//	MyVector<Edge_Status>Edges;
//	MyStack<string>Notification;
//	MyQueue<string>Friend_Request;
//	MyStack<string>Message;
//	MyStack<Post *>post;
//	void setName(string name)
//	{
//		this->Name = name;
//	}
//	void setPassword(double password)
//	{
//		this->Password = password;
//	}
//	void setCityName(string cityname )
//	{
//		this->City_Name = cityname;
//	}
//	void setNotification(string Notification)
//	{
//		this->Notification.push(Notification);
//	}
//	void setFriendRequest(string name)
//	{
//		this->Friend_Request.push(name);
//		setNotification("You Send a Friend Request to " + name);
//	}
//	void setPost(string Post_Content,string Post_Time)
//	{
//		Post* new_Post = new Post(Post_Content,Post_Time);
//		post.push(new_Post);
//		setNotification("You Post this " + Post_Content + " at " + Post_Time);
//	}
//	void sendMessage(string message)
//	{
//		this->Message.push(message);
//	}
//	void getMessage()
//	{
//		if (Message.isEmpty())
//		{
//			cout << "No Message to Show" << endl;
//			return;
//		}
//		while (Message.isEmpty() == false)
//		{
//			cout << "Message :: " << Message.peek() << endl;
//			Message.pop();
//		}
//		
//	}
//	void getNotifications()
//	{
//		if (Notification.isEmpty() == true)
//		{
//			cout << "Their is No Notifications to show" << endl;
//			return;
//		}
//		while (Notification.isEmpty() == false)
//		{
//			cout <<"Notification :: " << Notification.peek();
//			Notification.pop();
//			cout << endl;
//		}
//	}
//	void getPost()
//	{
//		if (post.isEmpty() == true)
//		{
//			cout << "No Post to Show" << endl;
//			return;
//		}
//		while (post.isEmpty() == false)
//		{
//			Post* obj = post.peek();
//			obj->showPost();
//			post.pop();
//			cout << endl;
//		}
//	}
//	string getName()
//	{
//		return Name;
//	}
//	string getCityName()
//	{
//		return City_Name;
//	}
//	double getPassword()
//	{
//		return Password;
//	}
//	void addEdge(Edge_Status new_Edge)
//	{
//		Edges.PushBack(new_Edge);
//	}
//	void showEdges()
//	{
//		if (Edges.size() == 0)
//		{
//			cout << "No Edges to Show" << endl;
//			return;
//		}
//		for (int i = 0; i < Edges.size(); i++)
//		{
//			Edges[i].getValue();
//		}
//	}
//	MyVector<Edge_Status>& getEdges()
//	{
//		return Edges;
//	}
//};
//class Graph
//{
//public:
//	MyVector<UserProfile>Users;
//	UserProfile& getVertexByName(string Name)
//	{
//		UserProfile Temp;
//		for (int i = 0; i < Users.size(); i++)
//		{
//			Temp = Users[i];
//			if (Users[i].getName() == Name)
//			{
//				return Users[i];
//
//			}
//		}
//		throw std::runtime_error("User not found");
//	}
//	bool checkIfUserExist(string Target_Name)
//	{
//		for (int i = 0; i < Users.size(); i++)
//		{
//			if (Target_Name == Users[i].getName())
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//	
//	void addUser(string Name,string CityName,double Password)
//	{
//		UserProfile new_Vertex;
//		new_Vertex.setName(Name);
//		new_Vertex.setPassword(Password);
//		std::cin.ignore();
//		std::cin.clear();
//		new_Vertex.setCityName(CityName);
//		bool Check = checkIfUserExist(new_Vertex.getName());
//		if (Check == false)
//		{
//			Users.PushBack(new_Vertex);
//		}
//		else
//		{
//			cout << "User is Already Exist " << endl;
//			return;
//		}
//		
//	}
//	void addEdge(string Source, string Target)
//	{
//		
//		bool Check_Source = checkIfUserExist(Source);
//		bool Check_Target = checkIfUserExist(Target);	
//		UserProfile& Source_User = getVertexByName(Source);
//		UserProfile& Target_User = getVertexByName(Target);
//		if (Check_Source == true && Check_Target == true)
//		{
//			
//			string Status;
//			string Relationship_Type;
//			cout << "Enter the Status :: ";
//			getline(cin, Status);
//			cout << "Enter the Relationship Type :: ";
//			getline(cin, Relationship_Type);
//			Edge_Status new_Edge(Status, Relationship_Type,Target);
//			Source_User.addEdge(new_Edge);
//			Target_User.addEdge(new_Edge);
//		
//
//			Target_User.setNotification(Source_User.Name + " make you  "+ Relationship_Type);
//			cout << "Friend Request Sent Succefully to "<< Target << endl;
//		}
//		else
//		{
//			cout << "One or Both User Can not Found " << endl;
//		}
//		
//	}
//	void display()
//	{
//		if (Users.size() == 0)
//		{
//			cout << "No User to Show" << endl;
//			return;
//		}
//		cout << "Users in the Graph" << endl;
//		for (int i = 0; i < Users.size(); i++)
//		{
//			cout << "User Name :: " << Users[i].getName() << endl;
//			cout << "City :: " << Users[i].getCityName()<<endl;
//			cout << "Password :: " << Users[i].getPassword() << endl;
//			Users[i].showEdges();
//		}
//	}
//	void UserMenu()
//	{
//		cout << "\n|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n";
//		cout << "  |1.Add Post                                 |\n";
//		cout << "  |2.Send Message                             |\n";
//		cout << "  |3.Show Message                              |\n";
//		cout << "  |4.Show  Notifications                        |\n";
//		cout << "  |5.Show Post                                 |\n";
//		cout << "  |6.Send Friend Request                      |\n";
//		cout << "  |7.Log Out                                  |\n";
//		cout << "  |8.Exit                                     |\n";
//		cout << "\n|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n";
//	}
//	void EnterInsta(string username)
//	{
//		for (int i = 0; i < Users.size(); i++)
//		{
//			if (Users[i].getName() == username)
//			{
//				while (true)
//				{
//					UserMenu();
//					int Choice;
//					cin >> Choice;
//					std::cin.clear();
//					std::cin.ignore();
//					if (Choice == 1)
//					{
//						string Post_Content;
//						MyVector<Edge_Status>Temp_Edge;
//						time_t now = time(0);
//						struct tm Local_Time;
//						localtime_s(&Local_Time, &now);
//						std::stringstream ss;
//						ss << Local_Time.tm_year + 1900 << "_" << Local_Time.tm_mon + 1 << "-" << Local_Time.tm_mday << "-" << Local_Time.tm_hour << "-" << Local_Time.tm_min << "-" << Local_Time.tm_sec;
//						string Post_Time = ss.str();
//						cout << "Enter the Post :: ";
//						getline(cin, Post_Content);
//						Users[i].setPost(Post_Content,Post_Time);
//						MyVector<Edge_Status>Temp_Edges = Users[i].getEdges();
//						for (int i = 0; i < Temp_Edge.size(); i++)
//						{
//							if (Temp_Edge[i].getRelationshipType() == "Friend")
//							{
//								UserProfile& Target_User = getVertexByName(Temp_Edge[i].getName());
//								Target_User.setNotification(Users[i].getName() + " Post this " + Post_Content + " at " + Post_Time);
//							}
//						}
//					}
//					else if (Choice == 2)
//					{
//						string message;
//						string Target_User;
//						cout << "Enter the Name of the Person to whom you want to send the Message ::";
//						getline(cin, Target_User);
//						bool CheckUser=false;
//						MyVector<Edge_Status>Temp_Edge = Users[i].getEdges();
//						for (int i = 0; i < Temp_Edge.size(); i++)
//						{
//							if (Temp_Edge[i].getRelationshipType() == "Friend" && Temp_Edge[i].getName() == Target_User)
//							{
//								CheckUser = true;
//								break;
//							}
//						}
//						if (CheckUser == false)
//						{
//							cout << "Your are Not Friend First Send Friend Request" << endl;
//							continue;
//						}
//						cout << "Enter the Message Which you want to send :: ";
//						getline(cin, message);
//						Users[i].sendMessage(message);
//						UserProfile& Target_user = getVertexByName(Target_User);
//						Target_user.setNotification(Users[i].getName() + " Send you a Message");
//						Target_user.setNotification(Users[i].getName() + " Send you a Message");
//					}
//					else if (Choice == 3)
//					{
//						Users[i].getMessage();
//					}
//					else if (Choice == 4)
//					{
//						Users[i].getNotifications();
//					}
//					else if (Choice == 5)
//					{
//						Users[i].getPost();
//					}
//					else if (Choice == 6)
//					{
//						string name;
//						cout << "Enter the Name of the Person to whom you want to send the Friend Request :: ";
//						getline(cin, name);
//						addEdge(Users[i].getName(),name);
//						Users[i].setFriendRequest(name);
//					}
//					else if (Choice == 7)
//					{
//						return;
//					}
//					else if (Choice == 8)
//					{
//						exit(0);
//					}
//					else
//					{
//						cout << "Invalid Choice" << endl;
//					}
//				}
//			}
//		}
//	}
//};
//class SignUP 
//{
//public:
//	string UserName;
//	double Password;
//	string Email;
//	string CityName;
//	SignUP() {}
//	SignUP(string UserName, double Password, string Email, string CityName)
//	{
//		this->UserName = UserName;
//		this->Password = Password;
//		this->Email = Email;
//		this->CityName = CityName;
//	}
//	void SignUp(string UserName, double Password, string Email, string CityName)
//	{
//		this->UserName = UserName;
//		this->Password = Password;
//		this->Email = Email;
//		this->CityName = CityName;
//	}
//	double getPassword()
//	{
//		return Password;
//	}
//	string getUserName()
//	{
//		return UserName;
//	}
//	void showSignUp()
//	{
//		cout << "User Name :: " << UserName << endl;
//		cout << "Password :: " << Password << endl;
//		cout << "Email :: " << Email << endl;
//		cout << "City Name :: " << CityName << endl;
//	}
//
//};
//void mainMenu();
//
//int main()
//{
//	system("color FC");
//	string UserName;
//	string Email;
//	string CityName;
//	double Password;
//	Graph obj;
//	int Choice=0;
//	MyVector <SignUP>SignUp;	
//
//	while (true)
//	{
//		mainMenu();
//		cin >> Choice;
//		if (Choice == 1)
//		{
//			cout << "Enter the User Name :: ";
//			cin.ignore();
//			getline(cin, UserName);
//			cout << "Enter the Password :: ";
//			cin >> Password;
//			bool Check = false;
//			for (int i = 0; i < SignUp.size(); i++)
//			{
//				if (SignUp[i].getUserName() == UserName && SignUp[i].getPassword() == Password)
//				{
//					Check = true;
//					break;
//				}
//			}
//			if (Check == true)
//			{
//				cout << "Log In Succefully" << endl;
//				obj.EnterInsta(UserName);
//			}
//			else
//			{
//				cout << "Invalid User Name or Password" << endl;
//			}	
//
//		}
//		else if (Choice == 2)
//		{
//			cout << "Enter the User Name :: ";
//			cin.ignore();
//			getline(cin, UserName);
//			cout << "Enter the Password :: ";
//			cin >> Password;
//			cout << "Enter the Email :: ";
//			cin.ignore();
//			getline(cin, Email);
//			cout << "Enter the City Name :: ";
//			cin.ignore();
//			getline(cin, CityName);
//			SignUP new_User(UserName, Password, Email, CityName);
//			SignUp.PushBack(new_User);
//			obj.addUser(UserName,CityName,Password);
//		}
//		else
//		{
//			cout << "Invalid Choice" << endl;
//		}
//	}
//	/*obj.addUser();
//	obj.addUser();
//	obj.addUser();
//
//	obj.addEdge();
//	obj.addEdge();
//
//	obj.display();*/
//	
//	system("pause");
//	return 0;
//}
//
//void mainMenu()
//{
//	cout << "\n|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n";
//	cout << "  |1.Log In                                   |\n";
//	cout << "  |2.Sign Up                                  |";
//	cout << "\n|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n";
//}