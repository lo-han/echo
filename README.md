# echo-lib
Echo request and reply message lib

## Infrastructure options

_Coming soon (ICMP)_

## Usage example

```c
Trigger trigger = NewTrigger();

if (trigger == NULL)
{
    return -1;
}

StartReceiving(trigger); // Loop

DestroyTrigger(&trigger);
```

## Tests

### Run unit tests

``` bash
python3 run_tests.py
```

### Run static checks

``` bash
python3 run_static_check.py
```

## Contribute

_Any idea or improvement is welcome. Feel free to branch and Pull Request for contributions, just, please, don't commit directly to develop or main histories. You can also get in contact with 'lohan.chuan123@gmail.com' or fork the repository._
