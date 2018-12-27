pragma solidity ^0.4.0;

contract produce48 {


    uint[] voteArray;
    idol[] idols;

    uint cooldownTime = 1 days;
    uint numberofidols;
    address contractowner;

    struct idol {
        string name;
        string agency;
    }
    mapping (address => bool) voters;
    mapping (address => uint) cooldown;
    mapping (uint => string) whois;
    mapping (uint => string) belongis;

    function contractown() public{
        contractowner = msg.sender;
    }


    function addidol(string name, string agency) public{
        bool add = true;
        for(uint8 i = 0; i < numberofidols; i++){
            if( (keccak256(whois[i]) == keccak256(name)) && (keccak256(belongis[i]) == keccak256(agency))){
                add = false; break;
            }
        }
        if(add){
            uint id = idols.push(idol(name, agency)) - 1;
            whois[id] = name;
            belongis[id] = agency;
            voteArray[id] = 0;
        }
    }

    function vote(uint id1, uint id2, uint id3, uint id4, uint id5, uint id6,
    uint id7, uint id8, uint id9, uint id10, uint id11, uint id12) public{

        if(cooldown[msg.sender] + cooldownTime >= now) voters[msg.sender] = false;
        if(voters[msg.sender]) {}
        else if(msg.sender == contractowner){
            voteArray[id1]++;voteArray[id2]++;voteArray[id3]++;voteArray[id4]++;voteArray[id5]++;voteArray[id6]++;
            voteArray[id7]++;voteArray[id8]++;voteArray[id9]++;voteArray[id10]++;voteArray[id11]++;voteArray[id12]++;
        }else{
            voters[msg.sender] = true;
            cooldown[msg.sender] = now;
            voteArray[id1]++;voteArray[id2]++;voteArray[id3]++;voteArray[id4]++;voteArray[id5]++;voteArray[id6]++;
            voteArray[id7]++;voteArray[id8]++;voteArray[id9]++;voteArray[id10]++;voteArray[id11]++;voteArray[id12]++;
        }
    }

    function alreadyVoted() constant public returns (bool) {
        if(voters[msg.sender]){
            return true;
        }
        else{
            return false;
        }
    }
    function getContractOwner() constant public returns (address) {
        return contractowner;
    }
    function getNumOfIdols() constant public returns (uint) {
        return numberofidols;
    }
    function getIdolname(uint id) constant public returns (string){
        return whois[id];
    }
    function getIdolAgency(uint id) constant public returns (string){
        return belongis[id];
    }
    function getScore(uint id) constant public returns (uint){
        return voteArray[id];
    }





}
