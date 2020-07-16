#include<iostream>
#include<string>
#include<vector>
using namespace std;
class item
{
private:
     string item_name;
	 string item_id;
	 string store_id;
	 float item_price;
public:
	item()
	{
	}
	item(string i_name,string i_id,string s_id,float i_pri)
	{
		this->item_name=i_name;
		this->item_id=i_id;
		this->store_id=s_id;
		this->item_price=i_pri;
	}
	//setters
	void set_itemname(string i_name)
	{
		this->item_name=i_name;

	}
	void set_itemid(string i_d)
	{
		this->item_id=i_d;
	
	}
	void set_storeid(string s_id)
	{
		this->store_id=s_id;
	
	}
	void set_itemprice(float i_pri)
	{
		this->item_price=i_pri;
	}
	//getters
	string get_itemname()
	{
	return item_name;

	}
	string get_itemid()
	{
		return item_id;
	
	}
	string get_storeid()
	{
		return store_id;
	
	}
	float get_itemprice()
	{
		return item_price;
	}
	friend ostream & operator << (ostream &,  item &obj);
	
};
//class itemnode
//{
//public:
//	item ITEM;
//	itemnode *next;
//
//	itemnode()
//	{
//		next=NULL;
//	}
//	itemnode(item ITEM)
//	{
//		this->ITEM=ITEM;
//		next=NULL;
//	}
//	itemnode(item ITEM,itemnode *n)
//	{
//		this->ITEM=ITEM;
//		next=n;
//	
//	}
//
//};

ostream& operator<<(ostream &out,  item &obj)
{
	out<<"ID : "<<obj.get_itemid()<<endl;
	out<<"Name : "<<obj.get_itemname()<<endl;
	out<<"Price : "<<obj.get_itemprice()<<endl;
	out<<"Store ID : "<<obj.get_storeid()<<endl;

    return out;
}

//class itemlist
//{
//    itemnode *head;
//public:
//    /*LinkedList()
//	{ 
//		head=NULL;
//	}*/
//
//    void addAtHead(item ITEM)
//	{
//        if (!head)
//			head=new itemnode(ITEM);
//        else
//			head=new itemnode(ITEM, head);
//    }
//    void show()
//	{
//    	for (itemnode *t=head;t!=NULL;t=t->next)
//    		cout<<*t<<' ';
//    	cout<<'\n';	
//	}
//};
class shopingcart
{
	vector <item> sta;
public:
	
	  void add_item(item ITEM)
	{
		sta.push_back(ITEM);
    }
	  vector<item> get_vector_item()
	  {
		  return sta;

	  
	  }
	  void remove_top()
	  {
		  sta.pop_back();
	  }
	  void remove_top_from_vector(){
				  sta.pop_back();
			  
	 }
	  void remove_item(item ITEM)
	  {
		  for (int i = 0; i < sta.size(); i++){
			  if (sta[i].get_itemname() == ITEM.get_itemname())
			  {
				  sta.erase(sta.begin() + i);
			  }
		  }
	  }
		  
		  
			//display fnstion	
	   void display()
	{
    	vector <item> sta1,sta2;
		item it;
			it=sta[sta.size()-1];
		    sta1.push_back(it);
			sta2.push_back(it);

			while(!sta1.empty())
			{
				cout<<sta1[sta.size()-1];
				sta1.pop_back();
			}
			while(!sta2.empty())
			{
				item it;
				it=sta2[sta2.size()-1];
				sta.push_back(it);
				sta2.pop_back();
			}
	}
};
		  class customer
		  {
		  private:
			  string customer_name;
			  shopingcart cart;
		  public:
			  void set_customername(string name )
			  {
				  this->customer_name=name;
			  }
			  shopingcart get_cart()
			  {
				  return cart;
			  
			  }
			  string get_customername()
			  {
				  return customer_name;
			  }

			  void addto_cart(item ITEM)
			  {
				  cart.add_item(ITEM);
			  }
			  void remove_cart(item ITEM)
			  {
				  cart.remove_item(ITEM);
			  }
			  void remove_top()
			  {
				  cart.remove_top();
			  }
			  void add (item i)
			  {
				  cart.add_item(i);
			  
			  }
		  
		  };
	  
		  class store
		  {
			  
		  protected:
			  string store_name;
			  string store_id;
			  vector <item> sta3;
			  vector <customer> vector_forcustomers;
		  public:
			  void set_storename(string storename)
			  {
				  this->store_name=storename;
			  }
			  void set_storeid(string storeid)
			  {
				  this->store_id=storeid;
			  }
			  string get_storename()
			  {
				  return store_name;
			  }
			  string get_storeid()
			  {
				  return store_id;
			  }
			  vector<item> get_vector()
			  {
				  return sta3;
			  
			  }
			  void remove_top_from_vector()
			  {
				  sta3.pop_back();
			  
			  }
			  void add_itemss(item i)
			  {
				  sta3.push_back(i); 
			  
			  }
			  void set_itemsinstore(item ITEM ,int total_items)
			  {
				  
				  for(int i=0;i<total_items;i++)
				  {
					  sta3.push_back(ITEM);
				  }
				  
				  /*string item_name,item_id;
				  int item_price;
				  cout<<"Enter item name : ";
				  cin>>item_name;

				  ite.set_itemname(item_name);

				  cout<<"Enter item id : ";
				  cin>>item_id;
				  ite.set_itemid(item_id);

				  cout<<"Enter item price :";
				  cin>>item_price;
				  ite.set_itemprice(item_price);

				  */
			  }
			  
			 item remove_fromstore()
				  {
					  item it;
					  if(!sta3.empty())
					  {
						  it = sta3[sta3.size() - 1];
					  sta3.pop_back();
					  return it;
					  }
				  }
			    virtual void show()=0;
				/*virtual void enter(customer c)=0; 
				virtual void exit(customer c) =0;
				virtual void addToCart(shopingcart,item)=0 ;
				virtual void removeFromCart(shopingcart, item)=0;*/


			  };
		 

		class bookstore :public store
		{
		public:
			bookstore(string Name)
			{
				item items;
				int number;
				set_storename(Name);
				set_storeid("rizwan");
				items.set_itemname("URDU");
				items.set_itemid("asdfghjk");
				items.set_itemprice(20);
				items.set_storeid("rizwan");
				cout<<"How many items you want to store ; ?";
					cin>>number;
					set_itemsinstore(items,number);

			}
			void show()
			{
				cout<<"Book store :"<<endl;
			}
			
		};
		class shoestore :public store
		{
		public:
			shoestore(string Name)
			{
				item items;
				int number;
				set_storename(Name);
				set_storeid("Borjan");
				items.set_itemname("chappal");
				items.set_itemid("qwert");
				items.set_itemprice(30);
				items.set_storeid("Borjan");
				cout<<"How many items you want to store ; ?";
					cin>>number;
					set_itemsinstore(items,number);

			}
			void show()
			{
				cout<<"Show store :"<<endl;
			}
		};
		class gamestore :public store
		{
		public:
			gamestore(string Name)
			{
				item items;
				int number;
				set_storename(Name);
				set_storeid("zulfi");
				items.set_itemname("gtycity");
				items.set_itemid("asdjf");
				items.set_itemprice(40);
				items.set_storeid("zulfi");
				cout<<"How many items you want to store ; ?";
					cin>>number;
					set_itemsinstore(items,number);

			}
			void show()
			{
				cout<<"Game store :"<<endl;
			}
		};
		class Mall
		{
		private:
				
					int total_customer;
					store *total_store[3];
			        string mall_name;
					customer cust;
		public:
					
				Mall(string mall_name)
				{
					cout << "Welcome to the "<<mall_name<< endl;
					this->mall_name = mall_name;
					Develope_Stores();
					make_customer();
				}
				void main_display()
				{
					system("cls");
					cout << "1. List of Stores" << endl;
					cout << "2. List of Items in Store" << endl;
					cout << "3. Enter a Store" << endl;
					cout<<" 4.  show cart :"<<endl;
					cout<<"5 . exit from mall :"<<endl;
					cout<<"6. check out :"<<endl;
					int select;
					cin >> select;
					if (select == 1)
					{
						store_list();
						system("pause");
						main_display();
					}
					else if (select == 2)
					{
						item_list();
					}
					else if (select == 3)
					{
						
						store_list();
						int var;
						cout << "Enter your choice: " << endl;
						cin >> var;
						if (var >= 1 && var <= 3)
						{
							enter_a_store(total_store[var-1]);

						}
						else
						{
							main_display();
						}
						
					}
					else if(select==4)
					{
						if(cust.get_cart().get_vector_item().empty())
						{
							cout<<"cart is empty"<<endl;
							system("pause");
							main_display();
						
						}
						else
						{
							cout<<"there are "<<cust.get_cart().get_vector_item().size() <<" is in the cart "<<endl<<endl;
							vector <item> sta4;
							while(!cust.get_cart().get_vector_item().empty())
							{
								
								cout << cust.get_cart().get_vector_item()[cust.get_cart().get_vector_item().size() - 1].get_itemname() << endl;
								sta4.push_back(cust.get_cart().get_vector_item()[cust.get_cart().get_vector_item().size() - 1]);
							cust.remove_top();
							
							
							}
							while(!sta4.empty())
							{
								cust.add(sta4[sta4.size()-1]);
								sta4.pop_back();
							
							}
							system("pause");
							main_display();

						}
					
					}
					else if(select==5)
					{
						exit_fromaal();
						make_customer();
					}
					else if(select==6)
					{
						checkcart();
					}
					else
					{
						main_display();
					}
				}

				void make_customer()
				{
					cout << "Enter customer Name: " << endl;
					string custname;
					cin >> custname;
					cust.set_customername(custname);
					main_display();
				
				}
				void checkcart()
				{
					float pric=0;
					while(!cust.get_cart().get_vector_item().empty())
					{
						pric = pric + cust.get_cart().get_vector_item()[cust.get_cart().get_vector_item().size()-1].get_itemprice();
						cust.remove_top();
					}
					cout<<"total price is : "<<pric<<endl;
					system("pause");
					make_customer();

				
				}
				void exit_fromaal()
				{
					while(!cust.get_cart().get_vector_item().empty())
					{
						for(int i=0;i<=2;i++)
						{
							if (cust.get_cart().get_vector_item()[cust.get_cart().get_vector_item().size() - 1].get_storeid() == total_store[i]->get_storeid())
							{
								total_store[i]->add_itemss(cust.get_cart().get_vector_item()[cust.get_cart().get_vector_item().size() - 1]);
								cust.remove_top();
								break;
							}
						
						}
					}
				}
				void enter_a_store(store *st)
				{
					system("cls");
					cout << "Welcome To " << st->get_storename()<<endl;
					cout << "there are " << st->get_vector().size() << " " << st->get_vector()[st->get_vector().size() - 1].get_itemname() << " in " << st->get_storename() << endl;
					cout << st->get_vector()[st->get_vector().size() - 1] << endl;
					cout<<"want to buy : ? (Y/N)";
					char select;
					cin>>select;
					if(select=='Y' || select=='y')
					{
						item it = st->get_vector()[st->get_vector().size() - 1];
						//st->get_vector().pop();
						st->remove_fromstore();
						cust.addto_cart(it);
						enter_a_store(st);
					
					}
					else
						main_display();
					
					system("pause");
				}
				void store_list()
				{
					system("cls");
					for (int i = 0; i <= 2; i++)
					{
						cout << i+1 <<" "<< total_store[i]->get_storename() << endl;
					}
					
				}
				void item_list()
				{
					system("cls");
					for (int i = 0; i <= 2; i++)
					{
						cout << "There are " << total_store[i]->get_vector().size() << ' ' << total_store[i]->get_vector()[total_store[i]->get_vector().size() - 1].get_itemname() << " Available in " << total_store[i]->get_storename() << endl;
					}
					system("pause");
					main_display();
				}
				void set_mall_name(string name)
				{
					mall_name = name;
				}
				void Develope_Stores()
				{
					string name1;
					cout << "Game Store Name:" << endl;
					cin >> name1;
					total_store[0] = new gamestore(name1);
					cout << "Book Store Name:" << endl;
					cin >> name1;
					total_store[1] = new bookstore(name1);
					cout << "Shoe Store Name:" << endl;
					cin >> name1;
					total_store[2] = new shoestore(name1);
					
				}

			
			
			
			

		};
		
		
		


		 

		  
	  

int main()
{
	string name;
	cin >> name;
	Mall obj(name);



	return 0;
}