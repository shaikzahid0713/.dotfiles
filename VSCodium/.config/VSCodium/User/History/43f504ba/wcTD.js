import React from 'react';
import { ReactDOM } from 'react';
import './index.css';

class Square extends React.Component {
    render() {
        return (
            <button className='square'>
                {this.props.value}
            </button>
        )
    }
}