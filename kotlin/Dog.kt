class Human {
  var name: String; 
}


class BadDog constructor (
  //private val ownerName: String | Human; 
) { 
  var owner : Human? = null; 
  val name: String = "Miu";
  var lastName: String? = null; 

  fun sayHi () {
    println("Hi, my name is $name and owner is $owner?.name")  
  }
}; 

