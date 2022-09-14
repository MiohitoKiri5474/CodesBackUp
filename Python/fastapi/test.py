from fastapi import FastAPI, Query, Path, Body
from typing import Optional
from pydantic import BaseModel, Field

app = FastAPI()

class Item ( BaseModel ):
    name: str
    description: Optional[str] = Field ( None, title = "The description of the item", max_length = 300 )
    price: float = Field ( ..., gt = 0, description = "The price must be greater then zero" )
    tax: Optional[float] = None

class User ( BaseModel ):
    username: str
    full_name: Optional[str] = None

@app.put ( "/items/{item_id}" )
async def update_item ( item_id: int, item: Item = Body ( ..., embed = True ) ):
    res = { "item_id": item_id, "item": item }
    return res
