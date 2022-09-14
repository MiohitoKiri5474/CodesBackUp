from fastapi import FastAPI
import uvicorn as u
from starlette.requests import Request
from starlette.staticfiles import StaticFiles
from starlette.templating import Jinja2Templates

app = FastAPI()

app.mount ( "/static", StaticFiles ( directory = "static" ), name = "static" )

templates = Jinja2Templates ( directory = "templates" )

@app.get ( "/items/{id}" )
async def read_item ( request: Request, id: str ):
    return templates.TemplateResponse ( "item.html", { "request": request, "id": id } )

if __name__ == '__main__':
    u.run ( app, host = "127.0.0.1", port = 8000 )
