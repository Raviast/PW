/* 4. You are developing a booking application for a cinema. The ticket price depends on the type of the
viewer("child", "adult", or "senior"). Write a program which calculates the price accordingly and prints the total
price to be paid. Let’s assume the ticket price for a child is Rs. 100, adult ticket price is Rs. 150 and ticket price
for a senior is Rs. 120+ */

let viewer = {
    child: 100,
    adult: 150,
    senior: 120
}

let numberOfChilds = 2;
let numberOfAdults = 1;
let numberOfSenior = 1;

function ticketPrice(numberOfChilds, numberOfAdults, numberOfSenior) {
    let price = numberOfChilds * viewer.child + numberOfAdults * viewer.adult + numberOfSenior*viewer.senior;
    return price
}

let Price = ticketPrice(numberOfChilds, numberOfAdults, numberOfSenior)
console.log("The total ticket price is ", Price);