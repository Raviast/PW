function formValidation()
{
    var uname = document.registration.username;
    var uemail = document.registration.email;
    var utele = document.registration.telephone;
    var passid = document.registration.passid;
    var uage = document.registration.age;
    var umsex = document.registration.msex;
    var ufsex = document.registration.fsex; 

    if(allLetter(uname))
    {
        if(ValidateEmail(uemail))
        {
            if(validateTelephone(utele))
            {
                if(passid_validation(passid, 7,12))
                {
                    if(age_validation(uage, 1,3))
                    {
                        if(validsex(umsex,ufsex))
                        {
                        }
                    }
                }
            }
        }               
    }

return false;

} 
function age_validation(age,mx,my)
{
var age_len = age.value.length;
if (age_len == 0 || uid_len >= my || uid_len < mx)
{
alert("User Id should not be empty / length be between "+mx+" to "+my);
uid.focus();
return false;
}
return true;
}
function passid_validation(passid,mx,my)
{
var passid_len = passid.value.length;
if (passid_len == 0 ||passid_len >= my || passid_len < mx)
{
alert("Password should not be empty / length be between "+mx+" to "+my);
passid.focus();
return false;
}
return true;
}
function allLetter(uname)
{ 
var letters = /^[A-Za-z]+$/;
if(uname.value.match(letters))
{
return true;
}
else
{
alert('Username must have alphabet characters only');
uname.focus();
return false;
}
}

function ValidateEmail(uemail)
{
var mailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
if(uemail.value.match(mailformat))
{
return true;
}
else
{
alert("You have entered an invalid email address!");
uemail.focus();
return false;
}
}
function validateTelephone(utele)
{
    var regPhone=/^\d{10}$/; 
    if(utele.value.match(regPhone))
    {
    return true;
    }
    else
    {
    alert("You have entered an invalid Mobile no!");
    utele.focus();
    return false;
    }
}
function validsex(umsex,ufsex)
{
x=0;

if(umsex.checked) 
{
x++;
} if(ufsex.checked)
{
x++; 
}
if(x==0)
{
alert('Select Male/Female');
umsex.focus();
return false;
}
else
{
alert('Form Succesfully Submitted');
window.location.reload()
return true;
}
}
