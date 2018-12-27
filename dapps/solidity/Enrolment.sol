pragma solidity ^0.4.11;

contract Enrolment {

event NewCourse(uint courseId, string name, string professor, string time, string room, uint credit, address creater);


  struct Course {
    string name;
    string professor;
    string time;
    string room;
    uint credit;
    address creator;
  }
  uint8 numberOfCourses = 0;
  Course[] public courses;

  function createCourse(string _name, string _professor, string _time, string _room, uint _credit) public {
    //courses[0] = Course(_name, _professor, _time, _room, _credit, msg.sender);
    uint id = courses.push(Course(_name, _professor, _time, _room, _credit, msg.sender)) - 1;
    NewCourse(id, _name, _professor, _time, _room, _credit, msg.sender);
    numberOfCourses++;
  }
  function getCourse(uint id) constant external returns(string, string, string, string, uint, address){
    return (courses[id].name, courses[id].professor, courses[id].time, courses[id].room, courses[id].credit, courses[id].creator);
  }

  function getname(uint id) constant public  returns(string){
    return courses[id].name;
  }
  function getprofessor(uint id) constant public  returns(string){
    return courses[id].professor;
  }
  function gettime(uint id) constant public  returns(string){
    return courses[id].time;
  }
  function getroom(uint id) constant public  returns(string){
    return courses[id].room;
  }
  function getcredit(uint id) constant public  returns(uint){
    return courses[id].credit;
  }
  function getnumberOfCourses() constant public returns(uint8){
    return numberOfCourses;
  }
}
