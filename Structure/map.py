class Map:
    def __init__(self, func, *iterables):
        self.func = func
        self.iterables = iterables
        self.iterators = [iter(it) for it in iterables]
    
    def __iter__(self):
        return self

    def __next__(self):
        try:
            args = [next(it) for it in self.iterators]
            return self.func(*args)
        except StopIteration:
            raise StopIteration
