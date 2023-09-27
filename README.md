# echo-lib
Echo request and reply message lib

## Infrastructure options

_Coming soon (ICMP)_

## Usage example

```c
Replier replier = NewReplier();

if (replier == NULL)
{
    return -1;
}

Trigger trigger = NewTrigger(replier);

if (trigger == NULL)
{
    return -1;
}

StartReceiving(trigger); // Loop

DestroyTrigger(&trigger);
DestroyReplier(&replier);
```

## Tests

### Run unit tests

``` bash
python3 run_tests.py
```

### Run static checks

``` bash
python3 run_tests.py
```
