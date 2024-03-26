Shaaf Shahzad, #501172227

Both requirements have been implemented without any issues.

QUESTION 1:
To handle standalone tags, we would need to implement logic to check the '/' before the closing '>'.
If it is detected, then the tag would not be pushed onto the stack as it does not require a closing end tag.