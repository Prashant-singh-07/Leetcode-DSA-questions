/**
 * @param {number[][]} questions
 * @return {number}
 */
var mostPoints = function(questions) {
    let n = questions.length;
    let arr = new Array(n);
    arr[n-1]=questions[n-1][0];
    for(let i=n-2;i>=0;i--){
        let take = questions[i][0];
        if(i+questions[i][1]+1 < n){
            take+=arr[1+questions[i][1]+i];
        }
        let notake = arr[i+1];
        arr[i] = Math.max(take,notake);
    }
    return arr[0];
};