/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
   
   for(x of nums){
      init = fn(init,x);
   }
    return init;
};