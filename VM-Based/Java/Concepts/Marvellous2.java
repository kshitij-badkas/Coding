// 1 - One class can extend another class
class Base
{}

class Derived extends Base
{}

///////////////////////////////////////////////////

// 2 - One class can implement one interface
interface Demo
{}

class Hello implements Demo
{}

///////////////////////////////////////////////////

// 3 - One class can implement more than one interface ----> replacement for multiple inheritance in Java
interface Hello
{}

interface Demo
{}

class Marvellous implements Hello, Demo
{}

///////////////////////////////////////////////////

// 4 - One interface can extend another interface
interface Demo
{}

interface Hello extends Demo
{}

class Marvellous implements Hello
{}

///////////////////////////////////////////////////

// 5 - One class can extend one class or implement one or more interfaces
class Demo
{}

interface Hello
{}

class Marvellous extends Demo implements Hello
{}

///////////////////////////////////////////////////
