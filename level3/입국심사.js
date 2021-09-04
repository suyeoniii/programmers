function solution(n, times) {
    var answer = 0;
    
    times.sort();
    
    var left = 0;
    var right = times[0]*n;
    
    while(left<=right){
        var mid = parseInt((left+right)/2);
        var person = 0;
        for(var j = 0; j<times.length; j++){
            person += parseInt(mid/times[j]);
        }
        
        if(n<=person){
            answer = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
        
    }
    
    return answer;
}
