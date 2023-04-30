## A05

- Name: Ernuel Tonge
- Date: 02 May 2023
- Class: 2143 OOP


## Definitions

#### Abstraction

> In computer science, Abstraction refers to the process of hiding complex implementation details while providing a simplified view of a system or program to its users. It is a fundamental concept in computer programming, design, and analysis, and is used to manage complexity and improve software design.
>
>Abstraction is achieved by defining a clear boundary between different parts of a system, such that users interact with the system through well-defined interfaces, rather than through the underlying implementation details. This allows users to focus on the higher-level functionality of the system without worrying about the low-level details.
>
>There are various types of abstraction in computer science, such as data abstraction, procedural abstraction, and control abstraction. Data abstraction involves defining abstract data types and operations on them, while procedural abstraction involves grouping related operations into functions or procedures. Control abstraction involves abstracting control flow constructs, such as loops and conditional statements.
>
>Overall, abstraction is an important tool for managing complexity in computer systems and is used extensively in software development to improve software design, maintainability, and scalability.
>
><img width="755" alt="image" src="https://user-images.githubusercontent.com/123034903/235331197-21671736-0456-4273-96c2-f3aa9d71c43f.png">
>
><img width="761" alt="image" src="https://user-images.githubusercontent.com/123034903/235331254-aba61b0f-c8a6-4c9e-b5b6-f3a9c2441086.png">
>
><img width="1199" alt="image" src="https://user-images.githubusercontent.com/123034903/235331410-1b34a0fc-0d7c-4412-9ec5-8bdc1c54fa0e.png">
>
><img width="1195" alt="image" src="https://user-images.githubusercontent.com/123034903/235331422-bb409307-a72f-4d5d-a9ab-d5ab7e8a46be.png">

### Attributes/Properties
>
>In computer science, attributes (also known as properties) refer to the characteristics or features of an object, data type, or program element. Attributes can be thought of as variables that are associated with an object or data type, and represent some aspect of its state or behavior.
>
>For example, in an object-oriented programming language, an object may have attributes such as a name, age, and address, which represent its state. These attributes can be accessed and modified by the object's methods, and can be used to control the behavior of the object.
>
>In database systems, attributes refer to the columns of a table, which represent the characteristics of the data being stored. For example, a table representing customers may have attributes such as a customer ID, name, email address, and phone number.
>
>Attributes can have different types, depending on the programming language or system being used. For example, attributes can be integers, strings, booleans, or complex data structures such as arrays or objects.
>
>Overall, attributes are a fundamental concept in computer science and are used extensively in programming, database systems, and other areas of computer science. They provide a way to represent and manipulate data, and allow for the creation of complex systems and applications.
>
>![image](https://user-images.githubusercontent.com/123034903/235331559-d486dac5-eddd-4bec-a1d5-9ee1971b9547.png)
>
>![image](https://user-images.githubusercontent.com/123034903/235331573-5fb2dbbf-1e8f-4a1e-b76d-9f2286ed78e9.png)
>
>![image](https://user-images.githubusercontent.com/123034903/235331594-4a22bd4a-cb7b-4e62-9b20-fcc79e156bec.png)
>
>Example code:
>
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def say_hello(self):
        print("Hello, my name is {} and I am {} years old.".format(self.name, self.age))

># Create a new person object and set its attributes
person1 = Person("John", 30)
>
># Access the attributes of the person object
print(person1.name)  # Output: "John"
print(person1.age)   # Output: 30
>
># Call a method on the person object that uses its attributes
person1.say_hello()  # Output: "Hello, my name is John and I am 30 years old."
>
>In this example, we define a class called Person that has two attributes: name and age. These attributes are set using the __init__ method, which is called when a new object of the class is created. We also define a method called say_hello that uses the attributes of the Person object to print a message.
>
>We then create a new Person object called person1 with the name "John" and age 30. We can access the attributes of person1 using dot notation (person1.name and person1.age), and call the say_hello method on person1 to print a message using its attributes.
>
>C++ Example code:
>
><img width="504" alt="image" src="https://user-images.githubusercontent.com/123034903/235331904-29d2096b-6fe9-487f-adf4-2fab9a72c3a9.png">
>
>In this example, we define a class called Person that has two attributes: name and age. These attributes are declared as public member variables, which means they can be accessed and modified from outside the class.
>
>We also define a method called say_hello that uses the attributes of the Person object to print a message.
>
>We then create a new Person object called person1, and set its attributes using dot notation (person1.name = "John" and person1.age = 30). We can access the attributes of person1 using dot notation (person1.name and person1.age), and call the say_hello method on person1 to print a message using its attributes.

### Class
>
>In computer science, a class is a blueprint or template that defines the characteristics and behaviors of a certain type of object. A class defines a set of attributes and methods that are common to all objects of that type.
>
>Attributes, also known as member variables or properties, represent the state or data associated with an object. Methods, also known as member functions or operations, represent the behavior or actions that can be performed on the object.
>
>A class typically encapsulates its attributes and methods, meaning that they are kept together and can only be accessed from within the class or through its public interface. The public interface is a set of methods that can be called from outside the class to interact with its objects.
>
>Here's an example of how a class can be defined in Python:
><img width="421" alt="image" src="https://user-images.githubusercontent.com/123034903/235332014-b5120d60-f330-4ae1-80ec-43a2acf1b4d3.png">
>
>In this example, we define a class called Rectangle that has two attributes: width and height. We also define two methods: area, which calculates the area of the rectangle, and perimeter, which calculates its perimeter.
>
>The __init__ method is a special method that is called when a new object of the class is created. It takes two arguments, width and height, and sets the corresponding attributes of the object.
>
>We can create new Rectangle objects using the class, and access their attributes and methods using dot notation:
>
><img width="371" alt="image" src="https://user-images.githubusercontent.com/123034903/235332045-da2a4743-b102-485a-9c9e-1012360af50d.png">
>
><img width="545" alt="image" src="https://user-images.githubusercontent.com/123034903/235332105-84b71319-2bbf-46a0-b802-7f5ab8e04f53.png">
>
>In this example, we define a class called Rectangle that has two private attributes: width and height. Private attributes can only be accessed from within the class, and not from outside.
>
>We also define two public methods: area, which calculates the area of the rectangle, and perimeter, which calculates its perimeter.
>
>The constructor of the Rectangle class takes two arguments, w and h, and initializes the width and height attributes of the object.
>
>We create a new Rectangle object called rect1 and calculate its area and perimeter using the area and perimeter methods. We can then print the results using cout.

### Class Variable
>
>In computer science, a class variable (also known as a static variable) is a variable that is shared by all instances of a class. In other words, a class variable is a property of the class itself, rather than a property of individual objects created from the class.
>
>Class variables are useful for storing data that is shared by all instances of a class. For example, if we have a class that represents a bank account, we might use a class variable to keep track of the interest rate for all accounts.
>
>Here's an example of how a class variable can be defined in Python:
>
```
class BankAccount:
    interest_rate = 0.05

    def __init__(self, balance):
        self.balance = balance

    def add_interest(self):
        self.balance += self.balance * BankAccount.interest_rate
```
>
>In this example, we define a class called `BankAccount` that has a class variable called `interest_rate`. We also define an `__init__` method that initializes the `balance` attribute of a new object, and a `add_interest` method that adds interest to the account balance.
>
>The `add_interest` method uses the `BankAccount.interest_rate` class variable to calculate the interest to be added.
>
>We can create new `BankAccount` objects using the class, and access the `interest_rate` class variable using dot notation:
>
```
acct1 = BankAccount(1000)
acct2 = BankAccount(5000)

print(acct1.balance)           # Output: 1000
print(acct2.balance)           # Output: 5000

print(BankAccount.interest_rate) # Output: 0.05

acct1.add_interest()
print(acct1.balance)           # Output: 1050.0
```
>
>In this example, both `acct1` and `acct2` share the same `interest_rate` class variable, which is set to `0.05`. When we call the `add_interest` method on `acct1`, it uses the `BankAccount.interest_rate` class variable to calculate the interest to be added.
>
>This demonstrates how a class variable can be defined and used to store data that is shared by all instances of a class.
>
>Here's an example of how a class variable can be defined in C++:
>
```
#include <iostream>
using namespace std;

class BankAccount {
public:
    static double interestRate;

    BankAccount(double balance) {
        this->balance = balance;
    }

    void addInterest() {
        balance += balance * interestRate;
    }

    double getBalance() {
        return balance;
    }

private:
    double balance;
};

double BankAccount::interestRate = 0.05;

int main() {
    BankAccount acct1(1000);
    BankAccount acct2(5000);

    cout << "Acct1 balance: " << acct1.getBalance() << endl;
    cout << "Acct2 balance: " << acct2.getBalance() << endl;

    acct1.addInterest();

    cout << "Acct1 balance after interest: " << acct1.getBalance() << endl;

    return 0;
}
```
>
>In this example, we define a class called `BankAccount` that has a class variable called `interestRate`. We use the `static` keyword to indicate that this variable is shared by all instances of the class.
>
>We also define a constructor that takes a `balance` argument and initializes the `balance` attribute of a new object. We define a `addInterest` method that adds interest to the account balance using the `interestRate` class variable. Finally, we define a `getBalance` method that returns the account balance.
>
>We initialize the `interestRate` class variable to `0.05` outside of the class definition, and access it using the scope resolution operator `BankAccount::` in the `addInterest` method.
>
>We create two new `BankAccount` objects called `acct1` and `acct2`, and print their initial balances using the `getBalance` method. We call the `addInterest` method on `acct1`, which adds interest to its balance using the `interestRate` class variable. We then print the updated balance of `acct1`.
>
>This is just a simple example, but it demonstrates how a class variable can be defined and used to store data that is shared by all instances of a class in C++.

### Composition
>
>In computer science, composition is a concept that refers to the ability to combine simple or complex objects to create more complex objects. Composition allows objects to be constructed from other objects, creating a hierarchical structure of objects.
>
>Composition is a form of object aggregation, where objects are combined to create a more complex object. Unlike inheritance, where a class inherits properties and methods from a parent class, composition allows objects to be combined in any way desired.
>
>In composition, an object is made up of one or more other objects, which are called its component objects. The component objects are created independently of the composite object, and they can be shared by multiple composite objects.
>
>Here's an example of how composition can be used in Python:
>
```
class Engine:
    def start(self):
        print("Engine started.")

class Car:
    def __init__(self):
        self.engine = Engine()

    def start(self):
        print("Starting car...")
        self.engine.start()

my_car = Car()
my_car.start()
```
>
>In this example, we have a `Car` class that is composed of an `Engine` class. The `Engine` class has a `start` method that prints "Engine started." The `Car` class has an `__init__` method that creates a new `Engine` object and assigns it to the `engine` attribute. The `Car` class also has a `start` method that calls the `start` method of the `Engine` object.
>
>When we create a new `Car` object and call its `start` method, it prints "Starting car..." and then calls the `start` method of the `Engine` object, which prints "Engine started." This demonstrates how composition can be used to create more complex objects from simpler objects.
>
>Composition allows objects to be composed in a flexible and dynamic way, making it a powerful tool for building complex software systems.
>
>Here's an example of how composition can be used in C++:
>
```
#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine started." << endl;
    }
};

class Car {
public:
    Car() {
        engine = new Engine();
    }

    void start() {
        cout << "Starting car..." << endl;
        engine->start();
    }

private:
    Engine* engine;
};

int main() {
    Car my_car;
    my_car.start();

    return 0;
}
```
>
>In this example, we have a `Car` class that is composed of an `Engine` class. The `Engine` class has a `start` method that prints "Engine started." The `Car` class has a constructor that creates a new `Engine` object using dynamic memory allocation and assigns it to a private `engine` pointer.
>
>The `Car` class also has a `start` method that prints "Starting car..." and then calls the `start` method of the `Engine` object using the `->` operator.
>
>When we create a new `Car` object and call its `start` method, it prints "Starting car..." and then calls the `start` method of the `Engine` object, which prints "Engine started." This demonstrates how composition can be used to create more complex objects from simpler objects.
>
>Composition allows objects to be composed in a flexible and dynamic way, making it a powerful tool for building complex software systems in C++.

### Constructor
>
>In computer science, a constructor is a special method that is used to initialize an object of a class. It is called when an object is created and is responsible for setting the initial values of the object's data members and performing any other necessary setup operations.
>
>In most object-oriented programming languages, a constructor is defined with the same name as the class and is usually declared as public. It can take parameters to allow for customization of the initialization process.
>
>Here's an example of a constructor in Python:
>
```
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

person1 = Person("Alice", 25)
```
>
>In this example, we have a `Person` class that has a constructor defined with the `__init__` method. The constructor takes two parameters, `name` and `age`, and assigns them to the object's `name` and `age` attributes.
>
>When we create a new `Person` object and pass in the values "Alice" and 25, the constructor is called automatically and initializes the object's `name` and `age` attributes with those values.
>
>Here's an example of a constructor in C++:
>
```
#include <iostream>
using namespace std;

class Person {
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

private:
    string name;
    int age;
};

int main() {
    Person person1("Alice", 25);
    person1.print();

    return 0;
}
```
>
>In this example, we have a `Person` class that has a constructor defined with the same name as the class. The constructor takes two parameters, `name` and `age`, and assigns them to the object's `name` and `age` data members using the `this` pointer.
>
>When we create a new `Person` object and pass in the values "Alice" and 25, the constructor is called automatically and initializes the object's `name` and `age` data members with those values. We then call the `print` method to output the values to the console.
>
>Constructors are a fundamental concept in object-oriented programming and are used extensively to initialize objects with default or custom values.

### Encapsulation
>
>In computer science, encapsulation is the concept of hiding the internal details of an object from the outside world and exposing a public interface through which other objects can interact with it. Encapsulation is a key principle of object-oriented programming and is often achieved through the use of access modifiers such as public, private, and protected.
>
>The public interface of an object consists of its methods and properties that are intended to be used by other objects. These methods and properties can be accessed from outside the object, but the internal details of how they work are hidden from view.
>
>Encapsulation provides several benefits, including:
>
>- Increased security: By hiding the internal details of an object, we can prevent unauthorized access and manipulation of its data.
>
>- Improved maintainability: Encapsulation allows us to make changes to the internal implementation of an object without affecting the way other objects interact with it.
>
>- Reduced complexity: By exposing only a public interface, we can simplify the way other objects interact with an object and reduce the complexity of the system as a whole.
>
>Here's an example of encapsulation in Java:
>
```
public class BankAccount {
    private double balance;

    public BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) {
        if (amount > balance) {
            throw new IllegalArgumentException("Insufficient funds");
        }
        balance -= amount;
    }

    public double getBalance() {
        return balance;
    }
}
```
>
>In this example, we have a `BankAccount` class that encapsulates a bank account with a balance. The `balance` variable is declared as private, which means that it can only be accessed from within the class itself.
>
>The class provides a public interface through the `deposit`, `withdraw`, and `getBalance` methods. These methods allow other objects to interact with the `BankAccount` object by depositing and withdrawing funds and retrieving the current balance.
>
>By encapsulating the `balance` variable and providing a public interface, we can ensure that the internal details of the `BankAccount` object are hidden from the outside world while still allowing other objects to interact with it in a controlled and secure way.

### Friends
>
>In computer science, a "friend" is a concept used in object-oriented programming that allows a function or class to access private or protected data of another class. A friend function or class is granted access to the private and protected members of another class, even though they are not members of that class.
>
>A friend function or class is declared using the `friend` keyword. This allows the specified function or class to access private and protected members of the class that declared it as a friend.
>
>Here's an example in C++:
>
```
class MyClass {
private:
    int privateData;

    friend int friendFunction(MyClass& myClass);

public:
    MyClass(int data) : privateData(data) {}

    int getPrivateData() {
        return privateData;
    }
};

int friendFunction(MyClass& myClass) {
    return myClass.privateData;
}

int main() {
    MyClass myObject(42);

    // Accessing privateData through friendFunction
    int data = friendFunction(myObject);

    std::cout << data << std::endl; // Outputs 42

    return 0;
}
```
>
>In this example, we have a `MyClass` class with a private member variable `privateData`. We also have a friend function `friendFunction` that takes a reference to a `MyClass` object and returns its `privateData` member.
>
>By declaring `friendFunction` as a friend of `MyClass`, we are granting it access to the private `privateData` member of `MyClass`. In the `main` function, we create a `MyClass` object and call `friendFunction` to access its private data.
>
>Note that friends can be useful in certain situations, but they can also violate the principles of encapsulation and make your code harder to maintain. Therefore, it's important to use friends sparingly and only when necessary.
>
>
>![image](https://user-images.githubusercontent.com/123034903/235333574-a583f4c9-fc3b-4689-b477-f778dcbe5da6.png)
>
>![image](https://user-images.githubusercontent.com/123034903/235333589-943ea6ea-f34b-4888-9104-b3e9fb627e6e.png)

### Inheritance
>
>In computer science, inheritance is a key concept in object-oriented programming that allows a new class to be based on an existing class, inheriting all of its properties and methods. The existing class is called the base class or parent class, and the new class is called the derived class or child class.
>
>The derived class inherits all the properties and methods of the base class, and it can also add new properties and methods or modify the behavior of inherited ones. This enables the reuse of code and reduces the amount of duplicate code.
>
>Inheritance is represented using an "is-a" relationship, where the derived class is a specialized version of the base class. For example, if we have a base class called Animal, we can create a derived class called Cat that inherits all the properties and methods of Animal, but also adds its own properties and methods specific to a cat.
>
>Here's an example of inheritance in C++:
>
>```
>#include <iostream>
>using namespace std;
>
>class Animal {
>protected:
>    string name;
>public:
>    Animal(string n) {
>        name = n;
>    }
>    void eat() {
>        cout << name << " is eating." << endl;
>    }
>    void sleep() {
>        cout << name << " is sleeping." << endl;
>    }
>};
>
>class Cat : public Animal {
>public:
>    Cat(string n) : Animal(n) {}
>    void meow() {
>        cout << "Meow!" << endl;
>    }
>};
>
>int main() {
>    Cat myCat("Fluffy");
>    myCat.eat(); // Calls eat() method from Animal class
>    myCat.sleep(); // Calls sleep() method from Animal class
>    myCat.meow(); // Calls meow() method from Cat class
>    return 0;
>}
>```
>
>In this example, we have a base class `Animal` that has a `name` property and two methods `eat` and `sleep`. We also have a derived class `Cat` that inherits from `Animal` and adds its own method `meow`.
>
>We create a `Cat` object in the `main` function and call its inherited methods `eat` and `sleep`, as well as its own method `meow`. The `public` keyword is used to indicate that `Cat` publicly inherits from `Animal`, meaning that all the public members of the `Animal` class are accessible in the `Cat` class.
>
>![image](https://user-images.githubusercontent.com/123034903/235333869-9683f1ec-ba31-47a1-a6ff-1406231d43ed.png)
>
>![image](https://user-images.githubusercontent.com/123034903/235333912-5f1592ad-58e1-42a2-8f6c-e18a829231db.png)

### Instance Variable
>In computer science, an instance variable is a variable that belongs to a specific instance of a class. It is also known as a non-static member variable, because it is not shared by all instances of the class and has a different value for each instance.
>
>When a new object is created from a class, it has its own set of instance variables that are initialized to their default values, or to the values provided in the constructor. Instance variables are typically declared as private or protected, to encapsulate the state of the object and prevent direct access from outside the class.
>
>Instance variables can be accessed and modified using the dot notation (.) on an object of the class, as in object.variable. They can also be accessed and modified from within the methods of the class using the this keyword, which refers to the current instance of the class.
>
>
>
>Here's an example in C++:
>
>```
>#include <iostream>
>using namespace std;
>
>class Car {
>    private:
>        string make;
>        string model;
>        int year;
>
>    public:
>        Car(string make, string model, int year) {
>            this->make = make;
>            this->model = model;
>            this->year = year;
>        }
>
>        void setMake(string make) {
>            this->make = make;
>        }
>
>        string getMake() {
>            return make;
>        }
>
>        void setModel(string model) {
>            this->model = model;
>        }
>
>        string getModel() {
>            return model;
>        }
>
>        void setYear(int year) {
>            this->year = year;
>        }
>
>        int getYear() {
>            return year;
>        }
>
>        void printDetails() {
>            cout << make << " " << model << " (" << year << ")" << endl;
>        }
>};
>
>int main() {
>    Car myCar("Toyota", "Corolla", 2022);
>    myCar.printDetails(); // Prints "Toyota Corolla (2022)"
>
>    myCar.setMake("Honda");
>    myCar.printDetails(); // Prints "Honda Corolla (2022)"
>
>    return 0;
>}
>```
>
>In this example, we have a class `Car` with three instance variables `make`, `model`, and `year`. The constructor takes these variables as parameters and initializes them to the values provided. We also have setter and getter member functions to access and modify the instance variables, and a `printDetails` member function to print the details of the car.
>
>We create a `Car` object in the `myCar` variable and call its `printDetails` member function to print the details of the car. We also use the `setMake` member function to change the value of the `make` instance variable to "Honda", and then call `printDetails` again to see the updated details.

### Member Variable
>
>In computer science, a member variable is a variable that is declared within a class definition and belongs to all instances of that class. It is also known as an instance variable or a member field.
>
>Member variables define the state or properties of an object, and they have a different value for each instance of the class. When an object is created from a class, it has its own set of member variables that are initialized to their default values or to the values provided in the constructor. Member variables are typically declared as private or protected to encapsulate the state of the object and prevent direct access from outside the class.
>
>To access and modify the member variables, we use member functions, which are also known as methods. By using member functions, we can control the access to the member variables and enforce certain rules and constraints on their values. This allows us to maintain the integrity of the object's state and ensure that it behaves as intended.
>
>
>Member variables are typically declared as private or protected, to encapsulate the state of the object and prevent direct access from outside the class. To access and modify the member variables, we use member functions.
>
>
>In summary, member variables are an essential part of object-oriented programming and allow us to define the state of an object, which can be accessed and modified through member functions.
>
>Here's an example in C++:
>
```
#include <iostream>
using namespace std;

class Rectangle {
    private:
        int width;
        int height;

    public:
        Rectangle(int width, int height) {
            this->width = width;
            this->height = height;
        }

        int getArea() {
            return width * height;
        }
};

int main() {
    Rectangle myRectangle(5, 3);
    cout << "Area of rectangle: " << myRectangle.getArea() << endl;

    return 0;
}
```
>
>In this example, we have a class `Rectangle` with two member variables `width` and `height`. The constructor takes these variables as parameters and initializes them to the values provided. We also have a `getArea` member function to calculate and return the area of the rectangle.
>
>We create a `Rectangle` object in the `myRectangle` variable and call its `getArea` member function to calculate and print the area of the rectangle. The `width` and `height` member variables are accessed through the `this` pointer, which refers to the current object.    
### Method
>In computer science, a method is a function that is associated with an object or a class in object-oriented programming. A method is similar to a function in procedural programming, but it is defined inside a class and operates on the data members of that class.
>
>A method is called on an object or an instance of a class, and it can access and modify the object's data members. Methods are used to define the behavior of objects and to perform operations on the object's data.
>
>In object-oriented programming, a method is typically declared within the class definition and is accessed using the dot notation, which is used to access the object's data members. The method can take arguments and return a value, just like a function.
>
>Here's an example in C++:
>
```c++
class Car {
public:
    void startEngine() {
        // code to start the engine
    }

    void stopEngine() {
        // code to stop the engine
    }

    void drive(int speed) {
        // code to drive the car at a given speed
    }
};

int main() {
    Car myCar;
    myCar.startEngine();
    myCar.drive(60);
    myCar.stopEngine();
    return 0;
}
```
>
>In this example, we have a class `Car` with three methods: `startEngine`, `stopEngine`, and `drive`. The `startEngine` method is used to start the car's engine, `stopEngine` method is used to stop the car's engine, and the `drive` method is used to drive the car at a given speed.
>
>We create an object of the `Car` class named `myCar` and call its methods using the dot notation. The `startEngine` method is called to start the car's engine, the `drive` method is called to drive the car at a speed of 60 miles per hour, and the `stopEngine` method is called to stop the car's engine.    
    
### Multiple Inheritance
>In computer science, multiple inheritance is a feature of object-oriented programming languages that allows a class to inherit from more than one base class. With multiple inheritance, a class can have access to the features and behavior of multiple parent classes.
>
>Multiple inheritance is useful when a class needs to inherit features from multiple sources, such as when a class needs to inherit both the characteristics of a mammal and the characteristics of a carnivore. Multiple inheritance allows a class to be more flexible and efficient by reusing existing code from different sources.
>
>However, multiple inheritance can also create some complexities and potential conflicts in the design of a program. For example, if two parent classes have a method with the same name, the derived class may have ambiguity about which method to call. This issue can be resolved through various techniques, such as renaming the method or using virtual inheritance.
>
>Here's an example in C++:
>
```c++
class Mammal {
public:
    void eat() {
        cout << "Eating like a mammal" << endl;
    }
};

class Carnivore {
public:
    void eat() {
        cout << "Eating like a carnivore" << endl;
    }
};

class Lion : public Mammal, public Carnivore {
public:
    void eat() {
        Mammal::eat(); // call Mammal's eat() method
        Carnivore::eat(); // call Carnivore's eat() method
    }
};

int main() {
    Lion lion;
    lion.eat(); // call Lion's eat() method, which calls Mammal and Carnivore's eat() methods
    return 0;
}
```
>
>In this example, we have two base classes `Mammal` and `Carnivore`, and a derived class `Lion` that inherits from both base classes using multiple inheritance. The `Lion` class has its own implementation of the `eat` method, which calls the `eat` methods of both the `Mammal` and `Carnivore` classes using scope resolution operator `::`. This allows the `Lion` class to exhibit both mammalian and carnivorous eating behavior.
        
### Object    
>    
>In computer science, an object is an instance of a class that represents a real-world entity, concept or idea. An object is created from a class, which defines the attributes (data) and behaviors (methods) of the object.
>
>In object-oriented programming, objects are the fundamental building blocks of a program. Each object has its own unique identity, which is defined by the data it contains and the behavior it exhibits. Objects can interact with other objects, either by calling methods or by accessing data.
>
>For example, consider a class `Car` that represents a real-world car. The class might have attributes such as `make`, `model`, `color`, and `year`, and behaviors such as `start`, `stop`, `accelerate`, and `brake`. An object of the `Car` class would represent a specific car, such as a red 2021 Toyota Camry.
>
>Here's an example of defining and using an object in C++:
>
```c++
class Car {
public:
    string make;
    string model;
    string color;
    int year;

    void start() {
        // code to start the car
    }

    void stop() {
        // code to stop the car
    }

    void accelerate() {
        // code to accelerate the car
    }

    void brake() {
        // code to apply the brakes
    }
};

int main() {
    Car myCar;
    myCar.make = "Toyota";
    myCar.model = "Camry";
    myCar.color = "Red";
    myCar.year = 2021;
    myCar.start();
    myCar.accelerate();
    myCar.brake();
    myCar.stop();
    return 0;
}
```
>
>In this example, we define a `Car` class with attributes for `make`, `model`, `color`, and `year`, and methods for `start`, `stop`, `accelerate`, and `brake`. We then create an object `myCar` of the `Car` class and set its attributes. Finally, we call the methods of the `myCar` object to simulate starting, accelerating, braking, and stopping a car.
    
### Overloading
>    
>In computer science, overloading is a feature of programming languages that allows the use of the same function or operator with different argument types or numbers of arguments. This means that multiple functions or operators can have the same name, but behave differently based on the types or number of their arguments.
>
>Function overloading occurs when multiple functions with the same name are defined in a class or namespace, but they differ in their number or types of parameters. Operator overloading is a specific type of function overloading that involves overloading operators such as +, -, *, and /, to work with custom types.
>
>Here's an example of function overloading in C++:
>
```c++
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    cout << add(2, 3) << endl;         // calls the first add function
    cout << add(2.5, 3.5) << endl;     // calls the second add function
    return 0;
}
```
>
>In this example, we define two functions with the same name `add`, but one takes two integers as parameters and returns an integer, while the other takes two doubles as parameters and returns a double. When we call the `add` function with integers as arguments, the first function is called, and when we call it with doubles as arguments, the second function is called.
>
>Overloading allows for more flexibility and reusability in code, as it enables us to define functions that behave similarly, but can operate on different types of data.
    
### Polymorphism
>
>In computer science, polymorphism is a feature of programming languages that allows objects of different types to be treated as if they are the same type, based on their behavior or attributes. Polymorphism allows for flexibility and reusability in code, as it enables the use of generic code that can work with different data types and objects, without needing to know their specific type.
>
>There are two main types of polymorphism: compile-time polymorphism (also known as static polymorphism) and runtime polymorphism (also known as dynamic polymorphism).
>
>
>Compile-time polymorphism is achieved through function overloading or operator overloading, where the compiler determines the appropriate function or operator to use based on the types and number of arguments passed.
>
>
>Runtime polymorphism is achieved through inheritance and virtual functions. In this case, objects of different derived classes are treated as objects of their common base class, and virtual functions are used to determine which version of the function to call based on the actual object type.
>
>Here's an example of runtime polymorphism using inheritance and virtual functions in C++:
>
```c++
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog;
    Animal* animal2 = new Cat;

    animal1->makeSound();   // calls Dog's makeSound() function
    animal2->makeSound();   // calls Cat's makeSound() function

    delete animal1;
    delete animal2;
    return 0;
}
```
>
>In this example, we have a base class `Animal` with a virtual function `makeSound()`. We then define two derived classes `Dog` and `Cat` that override the `makeSound()` function to produce different sounds. In the `main()` function, we create two pointers of type `Animal` that point to objects of `Dog` and `Cat`. When we call the `makeSound()` function through the pointers, the appropriate version of the function is called based on the actual object type. This is an example of runtime polymorphism, where objects of different types (derived classes) are treated as objects of their common base class.
>
>Here's an example of function overloading in C++:
>
```c++
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    int x = add(2, 3);
    double y = add(2.5, 3.7);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
```
>
>In this example, we have two functions named `add()` that have the same name but different parameters. One takes two integers and returns an integer, while the other takes two doubles and returns a double. When we call `add()` with different parameter types, the compiler determines which version of the function to call based on the types of the arguments passed. This is an example of compile-time polymorphism, as the appropriate function is selected by the compiler at compile time.    

    
### Public/Private/Protected    
>    
>In computer science, `public`, `private`, and `protected` are access specifiers used in object-oriented programming languages to specify the visibility of class members (variables and methods) to other parts of the program.
>
>
>- `public`: public members are accessible from any part of the program. They can be accessed by any object of the class, as well as by code outside the class. For example, a public method can be called from any part of the program.
>
>
>
>- `private`: private members are only accessible from within the class itself. They cannot be accessed by code outside the class, including objects of the same class. For example, a private method can only be called from within the class.
>
>
>- `protected`: protected members are similar to private members, but they can also be accessed by derived classes (subclasses) of the class. For example, a protected member variable can be accessed by a method in a derived class.
>
>Here's an example in C++:
>
```c++
#include <iostream>
using namespace std;

class MyClass {
public:
    int publicVar;      // can be accessed from anywhere
    void publicMethod() // can be called from anywhere
    {
        cout << "public method called" << endl;
    }

private:
    int privateVar;     // can only be accessed from within MyClass
    void privateMethod() // can only be called from within MyClass
    {
        cout << "private method called" << endl;
    }

protected:
    int protectedVar;   // can be accessed by MyClass and derived classes
    void protectedMethod() // can be called by MyClass and derived classes
    {
        cout << "protected method called" << endl;
    }
};

int main() {
    MyClass obj;

    obj.publicVar = 10; // can access public variable
    obj.publicMethod(); // can call public method

    // obj.privateVar = 20; // ERROR: cannot access private variable
    // obj.privateMethod(); // ERROR: cannot call private method

    // obj.protectedVar = 30; // ERROR: cannot access protected variable
    // obj.protectedMethod(); // ERROR: cannot call protected method

    return 0;
}
```
>
>In this example, we have a class named `MyClass` with public, private, and protected members. The public members can be accessed and called from anywhere in the program, while the private members can only be accessed and called from within the class itself. The protected members can be accessed and called by the class and its derived classes. In the `main()` function, we create an object of `MyClass` and demonstrate how the access specifiers work.
>
>![image](https://user-images.githubusercontent.com/123034903/235358904-22602043-7dbc-4026-bf7c-698d487c8b03.png)
>
>
>![image](https://user-images.githubusercontent.com/123034903/235358927-a2914521-479e-4147-9e4e-96ff1f419a94.png)    

    
### Static
>
>In computer science, `static` is a keyword used in programming languages to define a variable, function, or method that belongs to the class itself rather than an instance of the class. This means that the variable, function, or method can be accessed without creating an object of the class.
>
>In C++, a static variable declared in a class is shared by all objects of that class, rather than having separate copies for each object. A static member function is one that operates on static data members and does not have access to non-static data members.
>
>Here is an example of a static variable and a static member function in C++:
>
```
class MyClass {
public:
  static int staticVar;
  static void staticFunc() {
    cout << "Static function called" << endl;
  }
};

int MyClass::staticVar = 0;

int main() {
  MyClass obj1, obj2;
  
  obj1.staticVar = 5;
  obj2.staticVar = 10;
  
  cout << obj1.staticVar << endl;  // Outputs 10
  cout << obj2.staticVar << endl;  // Outputs 10
  
  MyClass::staticFunc();  // Outputs "Static function called"
  
  return 0;
}
```
>
>In this example, `staticVar` is a static variable that belongs to the `MyClass` class. It is initialized to 0 outside of the class definition. The `staticFunc` method is a static member function that can be called without creating an object of the class. When the `staticVar` variable is accessed through the `obj1` and `obj2` objects, the value is shared among all instances of the class. Finally, the `staticFunc` method is called using the class name `MyClass::` rather than an object name.   
    
### Virtual
>
>In computer science, `virtual` is a keyword used in object-oriented programming languages, such as C++, to enable dynamic polymorphism. When a function is declared as virtual, it means that the function can be overridden in derived classes.
>
>When an object calls a virtual function, the function that is called is determined at runtime, based on the actual type of the object. This allows for different behavior in derived classes, while still using the same function name and interface as the base class.
>
>Here's an example in C++:
>
```
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

int main() {
    Shape* shapePtr = new Circle;
    shapePtr->draw(); // Output: "Drawing a circle."
    delete shapePtr;
    return 0;
}
```
>
>In this example, the `Shape` class has a virtual `draw()` function, which is then overridden in the `Circle` class. In the `main()` function, a `Circle` object is created and assigned to a `Shape` pointer. When `draw()` is called on the `shapePtr`, the `Circle` class implementation of the function is executed, resulting in the output "Drawing a circle." If the `draw()` function was not virtual, the `Shape` class implementation would have been called instead, resulting in the output "Drawing a shape."
>
>![image](https://user-images.githubusercontent.com/123034903/235359331-048b5a13-fcd1-4a05-89fd-ce9c0f346409.png)
    
    
