/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let a = [];
    function myFunction(x,i){
        if(fn(x,i)) a.push(x);
    }
  arr.map(myFunction);
    
    
    return a;
};