import discord

intents = discord.Intents.default()
intents.messages = True

client = discord.Client(intents=intents)

@client.event
async def on_ready():
    print(f'We have logged in as {client.user}')

@client.event
async def on_message(message):
    # Don't allow the bot to reply to itself
    if message.author == client.user:
        return

    if message.content.startswith('!send'):
        msg = r"http://./\<#0>:  ://./<#0>"
        await message.channel.send(msg)

# Replace 'your_token_here' with your actual bot token
client.run('your_token_here')
