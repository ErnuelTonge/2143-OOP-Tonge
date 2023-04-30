##A05

Name: Ernuel Tonge
Date: 04 May 2023
Class: 2143 OOP

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
