function solution(s) {
    var answer = "";
    var isUp = true;
    
    for(let i = 0; i<s.length;i++){
        
        if(isUp) answer = answer+s[i].toUpperCase();
        else answer = answer+s[i].toLowerCase();
        
        isUp = !isUp;
        if(s[i] === ' ') isUp = true;
    }
    
    return answer;
}
