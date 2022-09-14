from fastapi import FastAPI
from typing import Optional
from pydantic import BaseModel

class Blog ( BaseModel ):
    title: str
    body: str
    published_at: Optional[bool]


app = FastAPI()

@app.get ( '/' )
def index():
    return { 'data': 'blog list' }

@app.get ( '/blog' )
def published ( limit = 10, published: bool = False, sort: Optional[str] = None ):
    if published:
        return { 'data': f'{limit} published blogs from the db' }
    else:
        return { 'data': f'{limit} blogs from the db' }

@app.get ( '/blog/unpoblished' )
def unpiblished():
    return { 'data': 'all unpoblished' }

@app.get ( '/blog/{id}' )
def show ( id: int ):
    return { 'blog_id': id }

@app.get ( '/blog/{id}/comments' )
def show_comments ( id: int = 1, limit: int = 10):
    res = { 'blog_id': id, 'comments': { '1', '2' } }
    res.update ( { 'limit': limit } )
    return res


@app.post ( '/blog' )
def creat ( req: Blog ):
    return { 'data': f"Blog is created with tittle at {req.title}" }
