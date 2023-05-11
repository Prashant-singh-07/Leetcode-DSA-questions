/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0) return false;
    
    let naya = x%10;
    let purana = x;
    x= x/10;
    x = Math.floor(x);
    let r;
    while(x>0){
        console.log(naya+"  "+x);
        r = x%10;
        naya*=10;
        naya += r;
        x = x/10;
        x = Math.floor(x);
    }
    console.log(naya);
    return naya==purana;
};