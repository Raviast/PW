/* You are building a shipping application. Write a program that takes the type of package ("standard",
"express", or "overnight") and uses a switch statement to calculate and print the estimated delivery time
based on the package type. For example, "standard" might take 3c5 days, "express" 1c2 days, and "overnight"
would be delivered the next day. */

let packageType = "standard";

switch (packageType) {
    case "standard":
        console.log("Estimated delivery time 3-5 days");
        break;
    case "express":
        console.log("Estimated delivery time 1-2 days");
        break;
    case "overnight":
        console.log("delivered the next day");
        break;

    default:
        console.log("Invalid package type");
        break;
}