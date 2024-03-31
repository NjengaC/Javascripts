import pathlib
import textwrap
from IPython.display import display, Markdown
from google.colab import userdata
import google.generativeai as genai
from langchain_google_genai import ChatGoogleGenerativeAI
import urllib
import warnings
from pathlib import Path as p
from pprint import pprint

import pandas as pd

from langchain import PromptTemplate
# Document Loader
from langchain.document_loaders import PyPDFLoader

# Splitter
from langchain.text_splitter import RecursiveCharacterTextSplitter

# Vector DataBase
from langchain.vectorstores import Chroma, FAISS, Pinecone

# Chains - sequence of calls
from langchain.chains import ConversationalRetrievalChain
from langchain.chains.question_answering import load_qa_chain

# Retrieve the API key
GOOGLE_API_KEY = userdata.get('Googler')

# Configure generative AI with the API key
genai.configure(api_key=GOOGLE_API_KEY)

model = ChatGoogleGenerativeAI(model="gemini-pro",temperature=0.3, google_api_key=GOOGLE_API_KEY)
