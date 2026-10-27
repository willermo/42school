def ft_filter(function, iterable):
    """ft_filter(function or None, iterable) --> filter object

Return an iterator yielding those items of iterable for which function(item)
is true. If function is None, return the items that are true.
"""
    func = bool if function is None else function
    for item in iterable:
        if func(item):
            yield item


"""
    The assignment is ambiguous in the definition itself.

    We have two mandatory statements:
    1. ft_filter should behave like the original built-in function
    2. you should use list comprehensions to recode your ft_filter

    Adherence to filter mimicking constraint is coded in the ft_filter
    definition provided, where ft_filter creates a generator object that yields
    the items of the iterable, for which the function evaluates to True.

    If we should adhere to constraint 2, the code should be instead something
    like this:

            def ft_filter(function, iterable):
                func = bool if function is None else function
                return [item for item in iterable if func(item)]

    Bottom line:
    The two constraint can't be concurrently satisfied.
    So I chose to satisfy constraint 1, as it is the most explicit one.
"""
