// Suppose you are building a payment checkout page and must display the final pri-e after the dis-ount+
// Create a simple discount calculator that takes two values from the variables - the total -ost and the
// discount percentage - and prints the discounted value+

let totalValue = 2000;
let discountPercentage = 20;

let discountedValue = totalValue - (totalValue*discountPercentage/100);

console.log("The final price after discount is: ", discountedValue);
