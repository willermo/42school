def NULL_not_found(object: any) -> int:
    match object:
        case None:
            print("Nothing", end=" ")
        case float():
            print("Cheese", end=" ")
        case False:
            print("Fake", end=" ")
        case 0:
            print("Zero", end=" ")
        case '':
            print("Empty", end=" ")
        case _:
            print("Type not found")
            return 1
    print(f": {object} {type(object)}")
    return 0
